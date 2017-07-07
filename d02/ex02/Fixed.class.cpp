#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

int const	Fixed::_fractBits = 8;

Fixed::Fixed(void) : _val(0) {
	return;
}

Fixed::Fixed(int const val) {
	this->_val = val << this->_fractBits;
	return;
}

Fixed::Fixed(float const val) {
	this->_val = std::roundf(val * (1 << this->_fractBits));
	return;
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
	return;
}

Fixed::~Fixed(void) {
	return;
}

Fixed			&Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

Fixed			Fixed::operator++() {
	this->_val++;
	return *this;
}

Fixed			Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_val++;
	return tmp;
}

Fixed			Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed			Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed			Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed			Fixed::operator/(Fixed const &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool			Fixed::operator>(Fixed const &rhs) const {
	return this->toFloat() > rhs.toFloat();
}

bool			Fixed::operator<(Fixed const &rhs) const {
	return this->toFloat() < rhs.toFloat();
}

bool			Fixed::operator>=(Fixed const &rhs) const {
	return this->toFloat() >= rhs.toFloat();
}

bool			Fixed::operator<=(Fixed const &rhs) const {
	return this->toFloat() <= rhs.toFloat();
}

bool			Fixed::operator==(Fixed const &rhs) const {
	return this->toFloat() == rhs.toFloat();
}

bool			Fixed::operator!=(Fixed const &rhs) const {
	return !(this->toFloat() == rhs.toFloat());
}

int				Fixed::getRawBits(void) const {
	return this->_val;
}

void			Fixed::setRawBits(int const raw) {
	this->_val = raw;
}

float			Fixed::toFloat(void) const {
	return this->_val * (1.0f / (1 << this->_fractBits));
}

int				Fixed::toInt(void) const {
	return this->_val >> this->_fractBits;
}

Fixed			&Fixed::max(Fixed &val1, Fixed &val2) {
	if (val1.toFloat() > val2.toFloat())
		return val1;
	else
		return val2;
}

Fixed const		&Fixed::max(Fixed const &val1, Fixed const &val2) {
	if (val1.toFloat() > val2.toFloat())
		return val1;
	else
		return val2;
}

Fixed			&Fixed::min(Fixed &val1, Fixed &val2) {
	if (val1.toFloat() < val2.toFloat())
		return val1;
	else
		return val2;
}

Fixed const		&Fixed::min(Fixed const &val1, Fixed const &val2) {
	if (val1.toFloat() < val2.toFloat())
		return val1;
	else
		return val2;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

int main() {
	Fixed a;
	Fixed d;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << (Fixed(100) + Fixed(3)) / 3  << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::max( a, Fixed(23.45f)) << std::endl;
	Fixed &c = Fixed::max( a, d );
	c = Fixed(40.23f);
	std::cout << Fixed::max( a, Fixed(23.45f)) << std::endl;
	std::cout << Fixed::max( c, Fixed(23.45f)) << std::endl;
	return 0;
}
