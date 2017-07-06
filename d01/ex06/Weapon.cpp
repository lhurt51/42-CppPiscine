#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

std::string Weapon::getType(void) const {
	return this->_type;
}

void		Weapon::setType(std::string type) {
	if (!type.empty())
		this->_type = type;
}
