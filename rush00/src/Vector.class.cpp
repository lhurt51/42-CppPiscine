#include <iostream>
#include "Vector.class.hpp"

Vector::Vector(void) : _x(0), _y(0) {
	return;
}

Vector::Vector(int x, int y) : _x(x), _y(y) {
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

int		Vector::getX(void) const {
	return this->_x;
}

int		Vector::getY(void) const {
	return this->_y;
}

void	Vector::setX(int x) {
	this->_x = x;
}

void	Vector::setY(int y) {
	this->_y = y;
}

std::ostream	&operator<<(std::ostream &o, Vector const &i) {
	return o << "(" << i.getX() << "," << i.getY() << ")";
}
