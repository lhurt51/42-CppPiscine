#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

int const	Fixed::_fractBits = 8;

Fixed::Fixed(void) : _val(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const val) {
	std::cout << "Int constructor called" << std::endl;
	this->_val = val * (1 << this->_fractBits);
	return;
}

Fixed::Fixed(float const val) {
	std::cout << "Float constructor called" << std::endl;
	this->_val = std::roundf(val * (1 << this->_fractBits));
	return;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed			&Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

int				Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void			Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float			Fixed::toFloat(void) const {
	return std::roundf(this->_val * (1 / (1 << this->_fractBits)));
}

int				Fixed::toInt(void) const {
	return this->_val * (1 / (1 << this->_fractBits));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i) {
	return o << i.getRawBits();
}

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
