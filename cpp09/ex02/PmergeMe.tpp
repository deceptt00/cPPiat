#include "PmergeMe.hpp"


template <typename T>
PmergeMe<T>::PmergeMe(char **av)
{
	if (!av)
		throw std::runtime_error("Error: no arguments provided");
	int ac = 0;
	long num;
	std::stringstream ss;
	while (av[ac])
	{
		ss << av[ac];
		ss >> num;
		if (ss.fail() || num < 0 || num > INT_MAX || std::string(av[ac]).find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Error: invalid argument");
		if (std::find(container.begin(), container.end(), static_cast<int>(num)) != container.end())
			throw std::runtime_error("Error: duplicate argument");
		container.push_back(static_cast<int>(num));
		ss.clear();
		ac++;
	}
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
	if (this != &other)
		container = other.container;
	return *this;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &cpy)
{
	if (this != &cpy)
		*this = cpy;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
typename PmergeMe<T>::iterator PmergeMe<T>::advance(iterator it, int n)
{
	std::advance(it, n);
	return it;
}

template <typename T>
typename PmergeMe<T>::it_iterator PmergeMe<T>::advance(it_iterator it, int n)
{
	std::advance(it, n);
	return it;
}

template <typename T>
void PmergeMe<T>::insert(int &jcp_curr, int &jcp_diff, int &inserted)
{
	it_iterator pend_it = advance(pend.begin(), jcp_diff - 1);
	int offset = 0;
		
	while (jcp_diff--){
		it_iterator bound = advance(main.begin(), jcp_curr + inserted - offset);
		it_iterator pos = std::upper_bound(main.begin(), bound, *pend_it, compare);
		it_iterator inserted_it = main.insert(pos, *pend_it);
		inserted++;
		
		pend_it = pend.erase(pend_it);
		std::advance(pend_it, -1);
		if (inserted_it - main.begin() == jcp_curr + inserted - offset)
			offset++;
	}
}

template <typename T>
void	PmergeMe<T>::insertion(int grp_size, int odd)
{
	int n = 2;
	int inserted = 0;
	int jcp_curr = jacobsthal(1);
	
	while (true){
		int jcp_prev = jcp_curr;
		jcp_curr = jacobsthal(n);
		int jcp_diff = jcp_curr - jcp_prev;
		if (jcp_diff > (int)pend.size())
			break;
		insert(jcp_curr, jcp_diff, inserted);
		n++;
	}
	// insert remainings
	for (ssize_t i = pend.size() - 1; i >= 0; i--){
		it_iterator pend_it = advance(pend.begin(), i);
		it_iterator bound = advance(main.begin(), main.size() - pend.size() + i + odd);
		it_iterator pos = std::upper_bound(main.begin(), bound, *pend_it, compare);
		main.insert(pos, *pend_it);
	}
	T copy;
	for (it_iterator it = main.begin(); it != main.end(); it++){
		for (int i = 0; i < grp_size; i++){
			iterator pair_start = *it;
			std::advance(pair_start, i - grp_size + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}
	std::copy(copy.begin(), copy.end(), container.begin());
}


template <typename T>
void PmergeMe<T>::makeChains(iterator &end, int grp_size, int groups, int odd)
{
	main.push_back(advance(container.begin(), grp_size - 1));
	main.push_back(advance(container.begin(), (grp_size * 2) - 1));
	for (int i = 4; i <= groups; i += 2)
	{
		pend.push_back(advance(container.begin(), (i - 1) * grp_size - 1));
		main.push_back(advance(container.begin(), i * grp_size - 1));
	}
	if (odd)
		pend.push_back(advance(end, grp_size - 1));
}

template <typename T>
void PmergeMe<T>::merge(int grp_size)
{
	int groups = container.size() / grp_size;
	if (groups < 2)
		return ;
	int odd = groups % 2 == 1;
	iterator iter = container.begin();
	iterator end = advance(container.begin(), ((groups - odd) * grp_size));
	for (; iter != end; std::advance(iter, grp_size * 2))
	{
		iterator curr = advance(iter, grp_size - 1);
		iterator next = advance(curr, grp_size);
		if (*next < *curr)
			std::swap_ranges(iter, advance(curr, 1) , advance(curr, 1));
	}
	merge(grp_size * 2);

	makeChains(end, grp_size, groups, odd);
	insertion(grp_size, odd);
	main.clear();
	pend.clear();
}

template <typename T>
void PmergeMe<T>::mergeInsertion()
{
	merge(1);
}