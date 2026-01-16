
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b(10);
	Fixed const c(13.37f);
	Fixed const d(b);

	a = c;
	a = Fixed(25.5f);
	b = a;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "+ operator : " << (c + b) << std::endl;
	std::cout << "- operator : " << (b - c) << std::endl;
	std::cout << "* operator : " << (b * c) << std::endl;
	std::cout << "/ operator : " << (b / c) << std::endl;


	if (c < b)
		std::cout << "c lower than b" << std::endl;
	else
		std::cout << "c greater than b" << std::endl;
	if (b == d)
		std::cout << "b equal d" << std::endl;
	else
		std::cout << "b different d" << std::endl;
	std::cout << a << " incrementation " << ++a << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	
	return 0;
}




