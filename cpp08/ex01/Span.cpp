#include "Span.hpp"

Span::Span(unsigned int N) : max(N)
{
    size = 0;
}

Span::Span(const Span &cpy) : max(cpy.max)
{
    size = cpy.size;
    for (unsigned int i = 0; i < size ;++i)
        numbers[i] = cpy.numbers[i];
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        size = other.size;
        max = other.max;
        for (unsigned int i = 0; i < size;++i)
            numbers[i] = other.numbers[i];
    }
    return *this;
}

Span::~Span()
{}

unsigned int Span::getMax()const{
    return max;
}

unsigned int Span::getSize()const{
    return numbers.size();
}

int Span::getNumAtIdx(unsigned int idx)const{
    return numbers.at(idx);
}

void    Span::addNumber(int val)
{
    if (numbers.size() >= max)
        throw std::runtime_error("Span is full");
    numbers.push_back(val);
    size = numbers.size();
}


unsigned int Span::shortestSpan()const
{
    if (numbers.size() < 2)
        throw std::out_of_range("No span can be found!Not enough elements");
    std::vector<int> tmp = numbers;
    
    std::sort(tmp.begin(), tmp.end());
    unsigned int shortest = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < size - 1;++i)
    {
        unsigned int span = static_cast<unsigned int>(tmp[i + 1]) - static_cast<unsigned int>(tmp[i]);
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

unsigned int Span::longestSpan()const
{
    if (numbers.size() < 2)
        throw std::out_of_range("No span can be found!Not enough elements");
   int max_el = *std::max_element(numbers.begin(), numbers.end());
   int min_el = *std::min_element(numbers.begin(), numbers.end());

   return (max_el - min_el);
}

