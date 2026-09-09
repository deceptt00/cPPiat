#include "PmergeMe.hpp"



template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) : vec_container(other.vec_container), deq_container(other.deq_container) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec_container = other.vec_container;
        deq_container = other.deq_container;

    }
    return *this;
}

template <typename T>
PmergeMe<T>::PmergeMe(char **av)
{
    while (*av)
    {
        std::string input(*av);

        if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Error: invalid character in input");

        std::istringstream iss(input);
        long value;
        iss >> value;

        if (iss.fail() || !iss.eof())
            throw std::invalid_argument("Error: failed to parse number");

        if (value < 0 || value > INT_MAX)
            throw std::invalid_argument("Error: number out of range");

        if (std::find(vec_container.begin(), vec_container.end(), value) != vec_container.end())
            throw std::invalid_argument("Error: duplicate number");

        vec_container.push_back(value);
        deq_container.push_back(value);

        ++av;
    }
}

template <typename T>
typename T::iterator PmergeMe<T>::next_it(typename std::vector<int>::iterator it, int n)
{
	std::advance(it, n);
	return it;
}

template <typename T>
typename T::iterator PmergeMe<T>::next_it(typename T::iterator it, int n)
{
	std::advance(it, n);
	return it;
}

template <typename T>
std::vector<size_t> PmergeMe<T>::jacobsthalOrder(size_t pendSize)
{
    if (pendSize == 0) return std::vector<size_t>();
    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < pendSize)
        jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);

    std::vector<size_t> order;
    size_t placed = 0;
    size_t lo = 0;
    for (size_t k = 0; placed < pendSize; ++k)
    {
        size_t hi = std::min(jacob[k], pendSize);
        for (size_t idx = hi; idx > lo; --idx)
        {
            order.push_back(idx - 1);
            ++placed;
        }
        lo = jacob[k];
    }
    return order;
}

template <typename T>
void PmergeMe<T>::appendBlock(T &result, typename T::iterator it, int depth)
{
    typename T::iterator blockStart = it;
    std::advance(blockStart, -(depth - 1));
    typename T::iterator blockEnd = it;
    ++blockEnd;
    result.insert(result.end(), blockStart, blockEnd);
}

template <typename T>
T PmergeMe<T>::insert(std::vector<typename T::iterator>& pend,
                       std::vector<typename T::iterator>& mainChain,
                       int depth, bool is_odd)
{
    T result;

    for (size_t i = 0; i < mainChain.size(); ++i)
        appendBlock(result, mainChain[i], depth);

    std::vector<size_t> mainBlockPos(mainChain.size());
    for (size_t i = 0; i < mainChain.size(); ++i)
        mainBlockPos[i] = i;

    size_t paired_pend_count = is_odd ? pend.size() - 1 : pend.size();
	std::vector<size_t> order = jacobsthalOrder(paired_pend_count);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t pendIdx = order[k];
        size_t hiBlock = mainBlockPos[pendIdx + 2];

        size_t lo = 0, hi = hiBlock;
        while (lo < hi)
        {
            size_t mid = lo + (hi - lo) / 2;
            typename T::iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend[pendIdx])
                lo = mid + 1;
            else
                hi = mid;
        }

        typename T::iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        typename T::iterator blockStart = pend[pendIdx];
        std::advance(blockStart, -(depth - 1));
        typename T::iterator blockEnd = pend[pendIdx];
        ++blockEnd;
        result.insert(insertPos, blockStart, blockEnd);

        for (size_t i = 0; i < mainBlockPos.size(); ++i)
            if (mainBlockPos[i] >= lo)
                mainBlockPos[i]++;
    }

    if (is_odd)
    {
        size_t lo = 0, hi = result.size() / depth;
        while (lo < hi)
        {
            size_t mid = lo + (hi - lo) / 2;
            typename T::iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend.back())
                lo = mid + 1;
            else
                hi = mid;
        }
        typename T::iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        typename T::iterator blockStart = pend.back();
        std::advance(blockStart, -(depth - 1));
        typename T::iterator blockEnd = pend.back();
        ++blockEnd;
        result.insert(insertPos, blockStart, blockEnd);
    }

    return result;
}

template <typename T>
void PmergeMe<T>::merge(int depth) {
	int pairs = container.size() / depth;
	if (pairs < 2)
		return;
	bool is_odd = pairs % 2 == 1;
	typename T::iterator begin = container.begin();
	typename T::iterator end = next_it(begin, depth * (pairs - is_odd));
	for (typename T::iterator it = begin; it != end; std::advance(it, 2 * depth)) {
		typename T::iterator curr = next_it(it, depth - 1);
		typename T::iterator next = next_it(it, depth * 2 - 1);
		if (!compare(curr, next))
			std::swap_ranges(it, next_it(it, depth), next_it(it, depth));
	}
	merge(depth * 2);
	std::vector<typename T::iterator> pend;
	std::vector<typename T::iterator> main;
	main.insert(main.end(), next_it(begin, depth - 1));
	main.insert(main.end(), next_it(begin, depth * 2 - 1));
	for (int i = 4; i <= pairs; i += 2) {
		pend.insert(pend.end(), next_it(begin, depth * (i - 1) - 1));
		main.insert(main.end(), next_it(begin, depth * i - 1));
	}
	if (is_odd)
		pend.insert(pend.end(), next_it(end, depth - 1));
	T result = insert(pend, main, depth, is_odd);
	std::copy(result.begin(), result.end(), container.begin());
}

template <typename T>
void PmergeMe<T>::printContainer(const T& container, const std::string& label)
{
    std::cout << label << ": ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

