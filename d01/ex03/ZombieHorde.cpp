#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

std::string const	ZombieHorde::_names[] = { "liam", "bob", "bobert", "carlos",
	"enzo", "amelia", "matt", "brio", "syra", "nissa", "rob", "tom", "bill",
	"becky", "bella", "ray", "reggie", "paul", "cade", "maddison" };

std::string const	ZombieHorde::_types[] = { "runner", "walker", "fat",
	"explosive", "crawler" };

ZombieHorde::ZombieHorde(int n) : _nbZombies(n) {
	if (this->_nbZombies > 0) {
		this->_zombieHorde = new Zombie[this->_nbZombies];
		for (int i = 0; i < this->_nbZombies; i++) {
			Zombie::setType(this->_types[rand() % 5]);
			this->_zombieHorde[i] = *(new Zombie(this->_names[rand() % 20]));
		}
	}
	return;
}

ZombieHorde::~ZombieHorde(void) {
	if (this->_zombieHorde)
		delete [] this->_zombieHorde;
	return;
}

void	ZombieHorde::announce(void) {
	if (this->_zombieHorde) {
		for (int i = 0; i < this->_nbZombies; i++) {
			this->_zombieHorde[i].anounce();
		}
	}
}
