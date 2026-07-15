#include "Array.hpp"
#include <iostream>
#include <string>

// Helper: print all elements of an Array<T>
template <typename T>
void printArray(const Array<T> &arr, const std::string &label)
{
	std::cout << label << " [size=" << arr.size() << "]: ";
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	// ── Default constructor (empty array) ────────────────────────────────
	std::cout << "=== Default constructor ===" << std::endl;
	{
		Array<int> empty;
		std::cout << "empty.size() = " << empty.size() << std::endl;
	}

	// ── Constructor with size ─────────────────────────────────────────────
	std::cout << "\n=== Array<int>(5): value-initialised to 0 ===" << std::endl;
	{
		Array<int> arr(5);
		printArray(arr, "arr");

		// Fill manually
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = static_cast<int>(i * 10);
		printArray(arr, "arr after fill");
	}

	// ── Copy constructor (deep copy) ──────────────────────────────────────
	std::cout << "\n=== Deep copy (modifying copy doesn't affect original) ===" << std::endl;
	{
		Array<int> original(3);
		original[0] = 1; original[1] = 2; original[2] = 3;

		Array<int> copy(original);
		copy[0] = 99;

		printArray(original, "original");
		printArray(copy,     "copy    ");
	}

	// ── Assignment operator (deep copy) ──────────────────────────────────
	std::cout << "\n=== Assignment operator ===" << std::endl;
	{
		Array<int> a(3);
		a[0] = 10; a[1] = 20; a[2] = 30;

		Array<int> b(5);
		b = a;
		b[0] = 999;

		printArray(a, "a");
		printArray(b, "b");
	}

	// ── Array<std::string> ────────────────────────────────────────────────
	std::cout << "\n=== Array<std::string> ===" << std::endl;
	{
		Array<std::string> words(3);
		words[0] = "hello";
		words[1] = "world";
		words[2] = "!";
		printArray(words, "words");
	}

	// ── Array<double> ─────────────────────────────────────────────────────
	std::cout << "\n=== Array<double> ===" << std::endl;
	{
		Array<double> d(4);
		d[0] = 1.1; d[1] = 2.2; d[2] = 3.3; d[3] = 4.4;
		printArray(d, "d");
	}

	// ── Out-of-bounds access ──────────────────────────────────────────────
	std::cout << "\n=== Out-of-bounds: index too large ===" << std::endl;
	{
		Array<int> arr(3);
		try {
			arr[5] = 42;
		} catch (std::exception &e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Out-of-bounds: access on empty array ===" << std::endl;
	{
		Array<int> empty;
		try {
			(void)empty[0];
		} catch (std::exception &e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
	}

	// ── const Array access ────────────────────────────────────────────────
	std::cout << "\n=== const Array access ===" << std::endl;
	{
		Array<int> arr(3);
		arr[0] = 7; arr[1] = 8; arr[2] = 9;
		const Array<int> &constRef = arr;
		std::cout << "constRef[1] = " << constRef[1] << std::endl;
		try {
			(void)constRef[10];
		} catch (std::exception &e) {
			std::cerr << "Caught: " << e.what() << std::endl;
		}
	}

	return 0;
}
