
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(13.37f);
	Fixed const d(b);

	a = c;
	a = Fixed(25.5f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "a = " << a.toFloat() << " as a float" << std::endl;
	std::cout << "b = " << b.toFloat() << " as a float" << std::endl;
	std::cout << "c = " << c.toFloat() << " as a float" << std::endl;
	std::cout << "d = " << d.toFloat() << " as a float" << std::endl;

	std::cout << "a = " << a.toInt() << " as integer" << std::endl;
	std::cout << "b = " << b.toInt() << " as integer" << std::endl;
	std::cout << "c = " << c.toInt() << " as integer" << std::endl;
	std::cout << "d = " << d.toInt() << " as integer" << std::endl;

	
	return 0;
}