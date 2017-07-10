#include <iostream>
#include <string>
#include <ncurses.h>
#include "Vector.class.hpp"
#include "Actor.class.hpp"

Actor::Actor(Vector pos, Vector size, std::string const *sprite) : _pos(pos), _size(size), _sprite(sprite), _bCollide(false) {
	return;
}

Actor::Actor(Actor const &src) : _size(src.getSize()), _sprite(src.getSprite()) {
	*this = src;
	return;
}

Actor::~Actor(void) {
	this->clear();
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

std::string	const	*Actor::getSprite(void) const {
	return this->_sprite;
}

void	Actor::setPos(Vector pos) {
	this->_pos = pos;
}

void	Actor::move(Vector pos) {
	this->_pos = this->_pos + pos;
}

bool	Actor::bDoesCollide(Actor &src) {
	if (this->_pos.getX() <= src._pos.getX() + src._size.getX()
		&& src._pos.getX() <= this->_pos.getX() + this->_size.getX()
		&& this->_pos.getY() <= src._pos.getY() + src._size.getY()
		&& src._pos.getY() <= this->_pos.getY() + this->_size.getY()) {
		src._hasCollided();
		this->_hasCollided();
		return true;
	}
	return false;
}

void	Actor::draw(void)
{
	for (uint16_t line = 0; line < this->_size.getY(); line++)
		mvprintw(this->_pos.getY() + line, this->_pos.getX(), this->_sprite[line].c_str());
}

void	Actor::clear(void)
{
	for (uint16_t y = 0; y < this->_size.getY(); y++)
		for (uint16_t x = 0; x < this->_size.getX(); x++)
			mvaddch(this->_pos.getY() + y, this->_pos.getX() + x, ' ');
}

void	Actor::_hasCollided(void) {
	this->_bCollide = true;
}
