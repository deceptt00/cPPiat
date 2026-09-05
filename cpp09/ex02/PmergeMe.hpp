#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

template <typename T>
class PmergeMe
{
	public:
		typedef typename T::iterator iterator;
		typedef typename std::vector<iterator>::iterator it_iterator;
		T	container;
		PmergeMe(){};
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	mergeInsertion();
	private:
		static bool compare(iterator it1, iterator it2) { return (*it1 < *it2); }
		void	insert(int &jcp_curr, int &jcp_diff, int &inserted);
		void	insertion(int grp_size, int odd);
		void 	makeChains(iterator &end, int grp_size, int groups, int odd);
		void	merge(int grp_size);

		std::vector<iterator> pend;
		std::vector<iterator> main;

		iterator advance(iterator it, int n);
		
		
		it_iterator advance(it_iterator it, int n);

};

int	jacobsthal(int n)
{
	//jacobsthal sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...
	 return round((pow(2, n + 1) + pow(-1, n)) / 3);
} 
