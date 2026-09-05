#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int max;
        unsigned int size;
    public:
        Span(unsigned int N);
        Span(const Span &cpy);
        Span &operator=(const Span &other);
        ~Span();

        unsigned int getMax()const;
        unsigned int getSize()const;
        int getNumAtIdx(unsigned int idx)const;
        void addNumber(int n);
        unsigned int shortestSpan()const;
        unsigned int longestSpan()const;
        template <typename I>
        void    addNumbers(I begin, I end);
};

template <typename I>
void Span::addNumbers(I begin, I end)
{
    if (numbers.size() + std::distance(begin, end) > max)
        throw std::out_of_range("Adding these elements would exceed Span capacity");
    numbers.insert(numbers.end(), begin, end);
    size = numbers.size();
}
