
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignement operator called" << std::endl;
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