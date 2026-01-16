
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

Fixed	Fixed::operator+(Fixed const &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(Fixed const &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(Fixed const &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(Fixed const &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

bool	Fixed::operator<(Fixed const &other) const {
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(Fixed const &other) const {
	if (this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &other) const {
	if (this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &other) const {
	if (this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &other) const {
	if (this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &other) const {
	if (this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed&	Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	operator--();
	return tmp;
}

int		Fixed::getRawBits() const {
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

Fixed &	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}

std::ostream&	operator<<(std::ostream& os, Fixed const &other) {
	os << other.toFloat();
	return os;
}