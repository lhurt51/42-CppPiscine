#include <iostream>
#include <string>
#include "Vector.class.hpp"
#include "Actor.class.hpp"
#include "Projectile.class.hpp"
#include "Game.class.hpp"

std::string const projectile_sprite[] = {"|"};

Projectile::Projectile(Vector pos) : Actor(pos, Vector(1, 1), projectile_sprite), _moveSpeed(2000) {
	return;
}

Projectile::Projectile(Projectile const &src) : Actor(src) {
	*this = src;
	return;
}

Projectile::~Projectile(void) {
	return;
}

Projectile	&Projectile::operator=(Projectile const &rhs) {
	if (this != &rhs) {
		this->setPos(rhs.getPos());
	}
	return *this;
}

void		Projectile::tick(void) {
	this->clear();
	this->_updatePos();
	this->_checkPos();
	this->draw();
}

void		Projectile::_checkPos(void) {
	if (this->getPos().getY() >= Game::getWinMaxY())
		this->_bCollide = true;
	else if (this->getPos().getY() <= 0)
		this->_bCollide = true;
	if (this->getPos().getX() >= Game::getWinMaxX())
		this->_bCollide = true;
	else if (this->getPos().getX() <= 0)
		this->_bCollide = true;
}

void		Projectile::_updatePos(void) {
	if (this->_moveSpeed <= 0) {
		this->move(Vector(0, -1));
		this->_moveSpeed = 2000;
	} else {
		this->_moveSpeed--;
	}

}
