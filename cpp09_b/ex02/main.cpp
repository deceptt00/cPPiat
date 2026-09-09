#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

double get_time_us()
{
    clock_t tv = clock();
    return (static_cast<double>(tv) * 1000000) / CLOCKS_PER_SEC;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>\n";
        return 1;
    }

    try 
    {

        PmergeMeVector vectorSorter(argv + 1);
        PmergeMeDeque dequeSorter(argv + 1);

        vectorSorter.printContainer(vectorSorter.container, "Before");

        
        double start = get_time_us();
        vectorSorter.merge(1);
        double end = get_time_us();
        double vec_time = end - start;

        start = get_time_us();
        dequeSorter.merge(1);
        end = get_time_us();
        double deq_time = end - start;
        //Time to process a range of 5 elements with std::[..] : 0.00014 us
        vectorSorter.printContainer(vectorSorter.container, "After ");
        std::cout << "Time to process a range of " << vectorSorter.container.size() << " elements of std::vector : " << std::fixed << std::setprecision(5) << vec_time << " us" << std::endl;
        std::cout << "Time to process a range of " << dequeSorter.container.size() << " elements of std::deque : " << std::fixed << std::setprecision(5) << deq_time << " us" << std::endl;

    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what()  << std::endl;
        return 1;
    }

    return 0;
}