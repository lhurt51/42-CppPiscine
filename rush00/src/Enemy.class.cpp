#include <iostream>
#include <string>
#include "Vector.class.hpp"
#include "Actor.class.hpp"
#include "Enemy.class.hpp"
#include "Game.class.hpp"

Enemy::Enemy(Vector pos, Vector const size, std::string const *sprite) :
	Actor(pos, size, sprite), _move_countdown(2800) {}

Enemy::Enemy(Enemy const &target) :
	Actor(target._pos, target._size, target._sprite), _move_countdown(2800)
{
	this->_bCollide = target._bCollide;
}

Enemy::~Enemy(void) {}

Enemy &Enemy::operator=(Enemy const &target)
{
	this->_pos = target._pos;
	this->_bCollide = target._bCollide;
	return *this;
}

void Enemy::tick(void)
{
	static Vector const speed(0, 1);
	if (this->_move_countdown == 0)
	{
		this->clear();
		this->move(speed);
		if (Game::getWinMaxY() < this->_pos.getY())
			this->_bCollide = true;
		this->_move_countdown = 2800;
		this->draw();
	}
	else
		this->_move_countdown -= 1;
}
