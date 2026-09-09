#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <string>


class PmergeMeVector
{
    public:
        typedef std::vector<int>::iterator iterator;

        PmergeMeVector() {}
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector(char **av);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        ~PmergeMeVector() {}

        iterator next_it(iterator it, int n);
        std::vector<size_t> jacobsthalOrder(size_t pendSize);
        void appendBlock(std::vector<int> &result, iterator it, int depth);
        std::vector<int> insert(std::vector<iterator> &pend,
                                 std::vector<iterator> &mainChain,
                                 int depth, bool is_odd);

        void merge(int depth);
        void printContainer(const std::vector<int> &container, const std::string &label);

        static bool compare(iterator it1, iterator it2) { return (*it1 < *it2); }

        std::vector<int> container;
};

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other) : container(other.container) {}

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &other)
{
    if (this != &other)
        container = other.container;
    return *this;
}

PmergeMeVector::PmergeMeVector(char **av)
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

        if (std::find(container.begin(), container.end(), value) != container.end())
            throw std::invalid_argument("Error: duplicate number");

        container.push_back(value);
        ++av;
    }
}

PmergeMeVector::iterator PmergeMeVector::next_it(iterator it, int n)
{
    std::advance(it, n);
    return it;
}

std::vector<size_t> PmergeMeVector::jacobsthalOrder(size_t pendSize)
{
    if (pendSize == 0)
        return std::vector<size_t>();
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

void PmergeMeVector::appendBlock(std::vector<int> &result, iterator it, int depth)
{
    iterator blockStart = it;
    std::advance(blockStart, -(depth - 1));
    iterator blockEnd = it;
    ++blockEnd;
    result.insert(result.end(), blockStart, blockEnd);
}

std::vector<int> PmergeMeVector::insert(std::vector<iterator> &pend,
                                         std::vector<iterator> &mainChain,
                                         int depth, bool is_odd)
{
    std::vector<int> result;

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
            iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend[pendIdx])
                lo = mid + 1;
            else
                hi = mid;
        }

        iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        iterator blockStart = pend[pendIdx];
        std::advance(blockStart, -(depth - 1));
        iterator blockEnd = pend[pendIdx];
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
            iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend.back())
                lo = mid + 1;
            else
                hi = mid;
        }
        iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        iterator blockStart = pend.back();
        std::advance(blockStart, -(depth - 1));
        iterator blockEnd = pend.back();
        ++blockEnd;
        result.insert(insertPos, blockStart, blockEnd);
    }

    return result;
}

void PmergeMeVector::merge(int depth)
{
    int pairs = container.size() / depth;
    if (pairs < 2)
        return;
    bool is_odd = pairs % 2 == 1;
    iterator begin = container.begin();
    iterator end = next_it(begin, depth * (pairs - is_odd));
    for (iterator it = begin; it != end; std::advance(it, 2 * depth))
    {
        iterator curr = next_it(it, depth - 1);
        iterator next = next_it(it, depth * 2 - 1);
        if (!compare(curr, next))
            std::swap_ranges(it, next_it(it, depth), next_it(it, depth));
    }
    merge(depth * 2);
    std::vector<iterator> pend;
    std::vector<iterator> mainChain;
    mainChain.insert(mainChain.end(), next_it(begin, depth - 1));
    mainChain.insert(mainChain.end(), next_it(begin, depth * 2 - 1));
    for (int i = 4; i <= pairs; i += 2)
    {
        pend.insert(pend.end(), next_it(begin, depth * (i - 1) - 1));
        mainChain.insert(mainChain.end(), next_it(begin, depth * i - 1));
    }
    if (is_odd)
        pend.insert(pend.end(), next_it(end, depth - 1));
    std::vector<int> result = insert(pend, mainChain, depth, is_odd);
    std::copy(result.begin(), result.end(), container.begin());
}

void PmergeMeVector::printContainer(const std::vector<int> &container, const std::string &label)
{
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

/* =====================================================================
 *  PmergeMeDeque : Ford-Johnson merge-insertion sort on std::deque<int>
 * ===================================================================== */
class PmergeMeDeque
{
    public:
        typedef std::deque<int>::iterator iterator;

        PmergeMeDeque() {}
        PmergeMeDeque(const PmergeMeDeque &other);
        PmergeMeDeque(char **av);
        PmergeMeDeque &operator=(const PmergeMeDeque &other);
        ~PmergeMeDeque() {}

        iterator next_it(iterator it, int n);
        std::vector<size_t> jacobsthalOrder(size_t pendSize);
        void appendBlock(std::deque<int> &result, iterator it, int depth);
        std::deque<int> insert(std::vector<iterator> &pend,
                                std::vector<iterator> &mainChain,
                                int depth, bool is_odd);

        void merge(int depth);
        void printContainer(const std::deque<int> &container, const std::string &label);

        static bool compare(iterator it1, iterator it2) { return (*it1 < *it2); }

        std::deque<int> container;
};

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &other) : container(other.container) {}

PmergeMeDeque &PmergeMeDeque::operator=(const PmergeMeDeque &other)
{
    if (this != &other)
        container = other.container;
    return *this;
}

PmergeMeDeque::PmergeMeDeque(char **av)
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

        if (std::find(container.begin(), container.end(), value) != container.end())
            throw std::invalid_argument("Error: duplicate number");

        container.push_back(value);
        ++av;
    }
}

PmergeMeDeque::iterator PmergeMeDeque::next_it(iterator it, int n)
{
    std::advance(it, n);
    return it;
}

std::vector<size_t> PmergeMeDeque::jacobsthalOrder(size_t pendSize)
{
    if (pendSize == 0)
        return std::vector<size_t>();
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

void PmergeMeDeque::appendBlock(std::deque<int> &result, iterator it, int depth)
{
    iterator blockStart = it;
    std::advance(blockStart, -(depth - 1));
    iterator blockEnd = it;
    ++blockEnd;
    result.insert(result.end(), blockStart, blockEnd);
}

std::deque<int> PmergeMeDeque::insert(std::vector<iterator> &pend,
                                       std::vector<iterator> &mainChain,
                                       int depth, bool is_odd)
{
    std::deque<int> result;

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
            iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend[pendIdx])
                lo = mid + 1;
            else
                hi = mid;
        }

        iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        iterator blockStart = pend[pendIdx];
        std::advance(blockStart, -(depth - 1));
        iterator blockEnd = pend[pendIdx];
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
            iterator rep = result.begin();
            std::advance(rep, mid * depth + (depth - 1));
            if (*rep < *pend.back())
                lo = mid + 1;
            else
                hi = mid;
        }
        iterator insertPos = result.begin();
        std::advance(insertPos, lo * depth);

        iterator blockStart = pend.back();
        std::advance(blockStart, -(depth - 1));
        iterator blockEnd = pend.back();
        ++blockEnd;
        result.insert(insertPos, blockStart, blockEnd);
    }

    return result;
}

void PmergeMeDeque::merge(int depth)
{
    int pairs = container.size() / depth;
    if (pairs < 2)
        return;
    bool is_odd = pairs % 2 == 1;
    iterator begin = container.begin();
    iterator end = next_it(begin, depth * (pairs - is_odd));
    for (iterator it = begin; it != end; std::advance(it, 2 * depth))
    {
        iterator curr = next_it(it, depth - 1);
        iterator next = next_it(it, depth * 2 - 1);
        if (!compare(curr, next))
            std::swap_ranges(it, next_it(it, depth), next_it(it, depth));
    }
    merge(depth * 2);
    std::vector<iterator> pend;
    std::vector<iterator> mainChain;
    mainChain.insert(mainChain.end(), next_it(begin, depth - 1));
    mainChain.insert(mainChain.end(), next_it(begin, depth * 2 - 1));
    for (int i = 4; i <= pairs; i += 2)
    {
        pend.insert(pend.end(), next_it(begin, depth * (i - 1) - 1));
        mainChain.insert(mainChain.end(), next_it(begin, depth * i - 1));
    }
    if (is_odd)
        pend.insert(pend.end(), next_it(end, depth - 1));
    std::deque<int> result = insert(pend, mainChain, depth, is_odd);
    std::copy(result.begin(), result.end(), container.begin());
}

void PmergeMeDeque::printContainer(const std::deque<int> &container, const std::string &label)
{
    std::cout << label << ": ";
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

#endif