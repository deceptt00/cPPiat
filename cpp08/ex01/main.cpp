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
        sp.addNumber(12);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(13);
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
    Span sp2(4);
    try
    {
        sp2.addNumbers(v.begin(), v.end());
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Span stress(10000);
    try
    {
        for (int i = 1; i <= 10000; i++)
        {
            stress.addNumber(i);
        }
        std::cout << "Shortest Span = " << stress.shortestSpan() << std::endl;
        std::cout << "Longest Span = " << stress.longestSpan() << std::endl;
            
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
