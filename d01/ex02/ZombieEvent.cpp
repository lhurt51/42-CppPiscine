#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string const	ZombieEvent::_names[] = { "liam", "bob", "bobert", "carlos",
	"enzo", "amelia", "matt", "brio", "syra", "nissa", "rob", "tom", "bill",
	"becky", "bella", "ray", "reggie", "paul", "cade", "maddison" };

ZombieEvent::ZombieEvent(void) {
	return;
}

ZombieEvent::~ZombieEvent(void) {
	return;
}

void	ZombieEvent::setZombieType(std::string type) {
	Zombie::setType(type);
}

Zombie* ZombieEvent::newZombie(std::string name) {
	if (!Zombie::getType().empty())
		return new Zombie(name);
	else
		std::cout << "Please set a type first" << std::endl;
	return new Zombie();
}

void	ZombieEvent::randomChump(void) {
	Zombie *tmp = this->newZombie(this->_names[rand() % 20]);
	if (!tmp->getName().empty())
		tmp->anounce();
	delete tmp;
}
