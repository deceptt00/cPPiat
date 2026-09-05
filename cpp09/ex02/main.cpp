#include "PmergeMe.tpp"

long long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL + tv.tv_usec);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: no arguments provided" << std::endl;
		return 1;
	}
	try
	{
		av++;
		PmergeMe<std::vector<int> > vec(av);
		PmergeMe<std::deque<int> > deq(av);
		{
			std::cout << "Before:\t";
			for (size_t i = 0; i < vec.container.size(); i++) std::cout << vec.container[i] << " ";
			std::cout << std::endl;
			long long start = get_time();
			vec.mergeInsertion();
			long long end = get_time();
			std::cout << "After:\t";
			for (size_t i = 0; i < vec.container.size(); i++)
				std::cout << vec.container[i] << " ";
			std::cout << std::endl;
			std::cout << "time to process a range of " << vec.container.size() << " elements with std::vector : " << std::fixed<< std::setprecision(5) << static_cast<double>(end - start) << " us" << std::endl;
		}
		{
			std::cout << "Before:\t";
			for (size_t i = 0; i < deq.container.size(); i++) std::cout << deq.container[i] << " ";
			std::cout << std::endl;
			long long start = get_time();
			deq.mergeInsertion();
			long long end = get_time();
			std::cout << "After:\t";
			for (size_t i = 0; i < deq.container.size(); i++)
				std::cout << deq.container[i] << " ";
			std::cout << std::endl;
			std::cout << "time to process a range of " << deq.container.size() << " elements with std::deque : " << std::fixed<< std::setprecision(5) << static_cast<double>(end - start) << " us" << std::endl;
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}