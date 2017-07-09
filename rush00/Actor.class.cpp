#include <iostream>
#include <string>
#include "Vector.class.hpp"
#include "Actor.class.hpp"

Actor::Actor(Vector pos, Vector size, char const sprite) : _pos(pos), _size(size), _sprite(sprite), _bCollide(false) {
	return;
}

Actor::Actor(Actor const &src) : _size(src.getSize()), _sprite(src.getSprite()) {
	*this = src;
	return;
}

Actor::~Actor(void) {
	return;
}

Actor	&Actor::operator=(Actor const &rhs) {
	if (this != &rhs) {
		this->_pos = rhs.getPos();
		this->_bCollide = rhs.getCollision();
	}
	return *this;
}

Vector	Actor::getPos(void) const {
	return this->_pos;
}

Vector	Actor::getSize(void) const {
	return this->_size;
}

bool	Actor::getCollision(void) const {
	return this->_bCollide;
}

char	Actor::getSprite(void) const {
	return this->_sprite;
}

void	Actor::setPos(Vector pos) {
	this->_pos = pos;
}

void	Actor::move(Vector pos) {
	this->_pos = this->_pos + pos;
}

bool	Actor::bDoesCollide(Actor &src) const {
	if (src.getCollision())
		return true;
	return false;
}

void	Actor::tick(void) {
	
}
