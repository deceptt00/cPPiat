#include "iter.hpp"
#include <iostream>
#include <string>

// ─── Example functions to pass to iter ───────────────────────────────────────

template <typename T>
void printElement(T const &x)
{
	std::cout << x << " ";
}

template <typename T>
void doubleElement(T &x)
{
	x *= 2;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = static_cast<char>(c - 32);
}

// ─── main ─────────────────────────────────────────────────────────────────────

int main(void)
{
	std::cout << "=== iter on int array (print) ===" << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		::iter(arr, 5, printElement<int>);
		std::cout << std::endl;
	}

	std::cout << "\n=== iter on int array (double each element) ===" << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		::iter(arr, 5, doubleElement<int>);
		::iter(arr, 5, printElement<int>);
		std::cout << std::endl;
	}

	std::cout << "\n=== iter on double array ===" << std::endl;
	{
		double arr[] = {1.1, 2.2, 3.3};
		::iter(arr, 3, printElement<double>);
		std::cout << std::endl;
	}

	std::cout << "\n=== iter on std::string array ===" << std::endl;
	{
		std::string arr[] = {"hello", "world", "from", "iter"};
		::iter(arr, 4, printElement<std::string>);
		std::cout << std::endl;
	}

	std::cout << "\n=== iter on char array (toUpper) ===" << std::endl;
	{
		char arr[] = {'h', 'e', 'l', 'l', 'o'};
		::iter(arr, 5, toUpper);
		::iter(arr, 5, printElement<char>);
		std::cout << std::endl;
	}

	std::cout << "\n=== iter on const int array (read-only print) ===" << std::endl;
	{
		const int arr[] = {10, 20, 30};
		::iter(arr, 3, printElement<int>);
		std::cout << std::endl;
	}

	return 0;
}
