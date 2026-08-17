#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data original;
	original.n = 42;
	original.s = "hello";
	original.d = 3.14;

	std::cout << "pointer address : " << &original << std::endl;
	std::cout << "   n = " << original.n << std::endl;
	std::cout << "   s = " << original.s << std::endl;
	std::cout << "   d = " << original.d << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "after Serialize: \n value (uintptr_t): " << raw << std::endl;

	Data *recovered = Serializer::deserialize(raw);
	std::cout << "after Deserialized: \n pointer address: " << recovered << std::endl;
	std::cout << "   n = " << recovered->n << std::endl;
	std::cout << "   s = " << recovered->s << std::endl;
	std::cout << "   d = " << recovered->d << std::endl;

	return 0;
}
