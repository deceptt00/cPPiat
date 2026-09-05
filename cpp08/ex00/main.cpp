#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iterator> 


int main()
{
    std::vector<int> v;
    for (int i = 0;i < 5; ++i)
        v.push_back(i);
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Element found : " << *it << std::endl;
        std::vector<int>::iterator it2 = easyfind(v, 10);
        std::cout << "Element found :" << *it2 <<std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::list<int> l;
    for (int i =0;i < 12;i++)
        l.push_back(i*2);
    try{
        std::list<int>::iterator l_it = easyfind(l, 34);
        std::cout << "Element found :" << *l_it <<std::endl;        
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}