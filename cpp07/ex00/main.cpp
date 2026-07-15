#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "=== swap, min, max with int ===" << std::endl;
	{
		int a = 2;
		int b = 3;
		std::cout << "Before: a=" << a << "  b=" << b << std::endl;
		::swap(a, b);
		std::cout << "After swap: a=" << a << "  b=" << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}

	std::cout << "\n=== swap, min, max with double ===" << std::endl;
	{
		double x = 1.5;
		double y = 9.9;
		std::cout << "Before: x=" << x << "  y=" << y << std::endl;
		::swap(x, y);
		std::cout << "After swap: x=" << x << "  y=" << y << std::endl;
		std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
		std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
	}

	std::cout << "\n=== swap, min, max with std::string ===" << std::endl;
	{
		std::string s1 = "apple";
		std::string s2 = "banana";
		std::cout << "Before: s1=" << s1 << "  s2=" << s2 << std::endl;
		::swap(s1, s2);
		std::cout << "After swap: s1=" << s1 << "  s2=" << s2 << std::endl;
		std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
		std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
	}

	std::cout << "\n=== equal values (min/max both return b) ===" << std::endl;
	{
		int a = 42;
		int b = 42;
		std::cout << "min(42, 42) = " << ::min(a, b) << std::endl;
		std::cout << "max(42, 42) = " << ::max(a, b) << std::endl;
	}

	return 0;
}
