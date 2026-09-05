#include "Span.hpp"
int main() {

    Span sp = Span(5);
    
    try
    {
        std::cout << sp.shortestSpan(); 
    }
    catch(std::exception &e)
    {
        std::cerr << e.what()<<std::endl;
    }
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span = " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span = " << sp.longestSpan() << std::endl;
        sp.addNumber(4);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what()<<std::endl;
    }
    std::vector<int> v;
    for (int i = 1; i <= 5; ++i)
        v.push_back(i * 10); // 10,20,30,40,50
    Span sp2(3);
    try
    {
        sp2.addNumbers(v.begin(), v.end());
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
