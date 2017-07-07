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
	this->_val = val << this->_fractBits;
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
	return this->_val;
}

void			Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float			Fixed::toFloat(void) const {
	return this->_val * (1.0f / (1 << this->_fractBits));
}

int				Fixed::toInt(void) const {
	return this->_val >> this->_fractBits;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}
