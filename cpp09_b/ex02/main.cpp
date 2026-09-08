#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>\n";
        return 1;
    }

    try 
    {
        // 1. Pass argv + 1 to skip the program name. 
        // The constructor handles all parsing and validation.
        PmergeMe< std::vector<int> > vectorSorter(argv + 1);
        PmergeMe< std::deque<int> > dequeSorter(argv + 1);

        // 2. Print the parsed container before sorting
        vectorSorter.printContainer(vectorSorter.container, "Before");

        // 3. Execute the sort
        vectorSorter.merge(1);
        dequeSorter.merge(1);

        // 4. Print after sorting
        vectorSorter.printContainer(vectorSorter.container, "After ");
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: Invalid input detected.\n";
        return 1;
    }

    return 0;
}