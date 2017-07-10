#include "Spawn.class.hpp"
#include "Enemy.class.hpp"
#include "Game.class.hpp"
#include <random>

std::string const Spawn::sprites[][1] = {
	{"( .-. )"},
	{"( .o.)"},
	{"( `·´ )"},
	{"( ︶︿︶)"},
	{"(\\/)(°,,,°)(\\/)"},
	{"(¬_¬)"},
	{"(~_^)"},
	{"(>_>)"}
};

Spawn::Spawn(void) : _rd(), _rng(this->_rd()),
	_uni_art(0, sizeof(Spawn::sprites) / sizeof(*Spawn::sprites) - 1),
	_uni_start(0, Game::getWinMaxX() - 15), _countdown(11000) {}

Spawn::Spawn(Spawn const &target)
{
	*this = target;
}

Spawn::~Spawn(void) {}

Spawn &Spawn::operator=(Spawn const &target)
{
	if (this != &target) {
		//this->_rd = target._rd;
		//this->_rng = target._rng;
		//this->_uni = target._uni;
	}
	return *this;
}

Enemy *Spawn::createEnemy(void)
{
	uint16_t dice_roll_art;
	uint16_t dice_roll_start;

	if (this->_countdown == 0)
	{
		dice_roll_art = this->_uni_art(this->_rng);
		dice_roll_start = this->_uni_start(this->_rng);
		if (dice_roll_start + Spawn::sprites[dice_roll_art][0].length() >= (unsigned long)Game::getWinMaxX())
			dice_roll_art -= Spawn::sprites[dice_roll_art][0].length();
		this->_countdown = 11000;
		return new Enemy(Vector(dice_roll_start, 0), Vector(Spawn::sprites[dice_roll_art][0].length(), 1), Spawn::sprites[dice_roll_art]);
	}
	this->_countdown -= 1;
	return NULL;
}
