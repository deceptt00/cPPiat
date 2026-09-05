#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int e)
{
    typename T::iterator it = std::find(container.begin(), container.end(), e);
    if (it != container.end())
        return it;
    throw std::runtime_error("Element not Found!");
};
