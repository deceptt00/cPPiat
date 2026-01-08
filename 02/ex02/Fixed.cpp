
#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(Fixed const &other) {
	*this = other;
}

Fixed::Fixed(const int n) {
	this->value = n << bits;
}

Fixed::Fixed(const float f) : value(f) {
	this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(Fixed const &other) {
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

std::ostream&	operator<<(std::ostream& o, Fixed const &other) {
	o << other.toFloat();
	return o;
}