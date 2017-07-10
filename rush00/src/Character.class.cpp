#include <iostream>
#include <string>
#include <ncurses.h>
#include "Vector.class.hpp"
#include "Actor.class.hpp"
#include "Character.class.hpp"
#include "Game.class.hpp"

Vector const Character::_start_location(47, 48);

std::string const player_sprite[] = {
	" /|\\ ",
	"/ | \\",
};

Character::Character(WINDOW *window) : Actor(Character::_start_location, Vector(6, 2), player_sprite), _window(window), _bExitRequested(false), _bIsFiring(false) {
	return;
}

Character::Character(Character const &src) : Actor(src) {
	*this = src;
	return;
}

Character::~Character(void) {
	return;
}

Character	&Character::operator=(Character const &rhs) {
	if (this != &rhs) {
		this->setPos(rhs.getPos());
		this->_inChar = rhs.getInChar();
		this->_bExitRequested = rhs.getExitRequest();
	}
	return *this;
}

int			Character::getInChar(void) const {
	return this->_inChar;
}

bool		Character::getExitRequest(void) const {
	return this->_bExitRequested;
}

void 		Character::tick(void) {
	this->_inChar = wgetch(this->_window);
	this->clear();
	this->_handleUserInput();
	this->_checkPos();
	this->draw();
}

Projectile	*Character::fire(void) {
	if (this->_bIsFiring)
		return new Projectile(this->getPos() + Vector(2, -3));
	return NULL;
}

void		Character::_checkPos(void) {
	if (this->getPos().getX() + this->getSize().getX() >= Game::getWinMaxX())
		this->setPos(Vector(Game::getWinMaxX() - this->getSize().getX(), this->getPos().getY()));
	else if (this->getPos().getX() <= 0)
		this->setPos(Vector(1, this->getPos().getY()));
	if (this->getPos().getY() + this->getSize().getY() >= Game::getWinMaxY())
		this->setPos(Vector(this->getPos().getX(), Game::getWinMaxY() - this->getSize().getY()));
	else if (this->getPos().getY() <= 0)
		this->setPos(Vector(this->getPos().getX(), 1));
}

void		Character::_handleUserInput(void) {
	this->_bIsFiring = false;
	switch(this->_inChar) {
		case 'q':
			this->_bExitRequested = true;
			break;
		case KEY_UP:
		case 'w':
			this->move(Vector(0, -1));
			break;
		case KEY_DOWN:
		case 's':
			this->move(Vector(0, 1));
			break;
		case KEY_LEFT:
		case 'a':
			this->move(Vector(-2, 0));
			break;
		case KEY_RIGHT:
		case 'd':
			this->move(Vector(2, 0));
			break;
		case ' ':
    		this->_bIsFiring = true;
			break;
		default:
			break;
	}
}

void		Character::_hasCollided(void)
{
	this->_bCollide = false;
	this->clear();
	this->setPos(Character::_start_location);
	//TODO: score drop
}
