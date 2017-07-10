#include <iostream>
#include "Vector.class.hpp"

Vector::Vector(void) : _x(0), _y(0) {
	return;
}

Vector::Vector(uint16_t x, uint16_t y) : _x(x), _y(y) {
	return;
}

Vector::Vector(Vector const &src) {
	*this = src;
	return;
}

Vector::~Vector(void) {
	return;
}

Vector	&Vector::operator=(Vector const &rhs) {
	if (this != &rhs) {
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

Vector	Vector::operator+(Vector const &rhs) const {
	return Vector(this->_x + rhs.getX(), this->_y + rhs.getY());
}

Vector	Vector::operator-(Vector const &rhs) const {
	return Vector(this->_x - rhs.getX(), this->_y - rhs.getY());
}

Vector	Vector::operator*(Vector const &rhs) const {
	return Vector(this->_x * rhs.getX(), this->_y * rhs.getY());
}

Vector	Vector::operator/(Vector const &rhs) const {
	return Vector(this->_x / rhs.getX(), this->_y / rhs.getY());
}

bool	Vector::operator==(Vector const &rhs) const {
	return (this->_x == rhs.getX() && this->_y == rhs.getY());
}

bool	Vector::operator!=(Vector const &rhs) const {
	return !(this->_x == rhs.getX() && this->_y == rhs.getY());
}

uint16_t		Vector::getX(void) const {
	return this->_x;
}

uint16_t		Vector::getY(void) const {
	return this->_y;
}

void	Vector::setX(uint16_t x) {
	this->_x = x;
}

void	Vector::setY(uint16_t y) {
	this->_y = y;
}

std::ostream	&operator<<(std::ostream &o, Vector const &i) {
	return o << "(" << i.getX() << "," << i.getY() << ")";
}
