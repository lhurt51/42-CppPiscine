#include <iostream>
#include <string>
#include "Zombie.hpp"

std::string	Zombie::_type = "";

Zombie::Zombie(void) {
	return;
}

Zombie::Zombie(std::string name) : _name(name) {
	this->_setInstType();
	return;
}

Zombie::~Zombie(void) {
	return;
}

void		Zombie::anounce(void) const {
	std::cout << "<name: " << this->getName() << " (type: " << this->getInstType() << ")> Braiiiiiiinnnssss..." << std::endl;
}

std::string	Zombie::getName(void) const {
	return this->_name;
}

std::string	Zombie::getInstType(void) const {
	return this->_instType;
}

void		Zombie::_setInstType(void) {
	this->_instType = Zombie::getType();
}

std::string Zombie::getType(void) {
	return Zombie::_type;
}

void		Zombie::setType(std::string type) {
	Zombie::_type = type;
}
