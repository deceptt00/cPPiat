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
#include <ctime>


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

// ===========================================================================================================

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


#endif