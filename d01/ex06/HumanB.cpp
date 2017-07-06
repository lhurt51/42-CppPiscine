#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name) {
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::attack(void) const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
