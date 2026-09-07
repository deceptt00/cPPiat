#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>


template <typename T>
class PmergeMe 
{
    public:
        PmergeMe() {};
        PmergeMe(PmergeMe &other);
        PmergeMe(char **av);
        PmergeMe &operator=(PmergeMe &other);
        ~PmergeMe();
        
        typename T::iterator next(typename T::iterator it, int n);

        void merge(int depth);

        T &getcontainer{};

	private:
        T container;



};




template <typename T>
PmergeMe<T>::PmergeMe(char **av)
{
    while (*av)
    {
        long value;
        std::string input(*av)
		std::istringstream iss(input);
        
        if(input.find_first_not_of("0123456789") != std::string::npos)
        //throw
		iss >> value;
		if (iss.fail() || std::find(con.begin(), con.end(), value) != con.end() || value || value < 0 || value > INT_MAX)
        //throw
		container.push_back(value);
		av++;
    }
}

template <typename T>
typename T::iterator PmergeMe<T>::next(typename T::iterator it, int n)
{
	std::advance(it, n);
	return it;
}



template <typename T>
void PmergeMe<T>::merge(int depth) {
	int pairs = container.size() / depth;
	if (pairs < 2)
		return;
	bool is_odd = pairs % 2 == 1;
	T::iterator begin = container.begin();
	T::iterator end = next(begin, depth * (pairs - is_odd));
	for (T::iterator it = begin; it != end; std::advance(it, 2 * depth)) {
		T::iterator curr = next(it, depth - 1);
		T::iterator next = next(it, depth * 2 - 1);
		if (!compare(curr, next))
			swap(curr, next);
	}
	merge(depth * 2);
	std::vector<T::iterator> pend;
	std::vector<T::iterator> main;
	main.insert(main.end(), next(begin, depth - 1));
	main.insert(main.end(), next(begin, depth * 2 - 1));
	for (int i = 4; i <= pairs; i += 2) {
		pend.insert(pend.end(), next(begin, depth * (i - 1) - 1));
		main.insert(main.end(), next(begin, depth * i - 1));
	}
	if (is_odd)
		pend.insert(pend.end(), next(end, depth - 1));
	T result = insert(pend, main, depth, is_odd);
	std::copy(result.begin(), result.end(), container.begin());
}



#endif