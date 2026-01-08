
#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << bits;
}

Fixed::Fixed(const float f) : value(f) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat() const {
	return (float)this->value / (float)(1 << bits);
}

int		Fixed::toInt() const {
	return this->value >> bits;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &other) {
	o << other.toFloat();
	return o;
}