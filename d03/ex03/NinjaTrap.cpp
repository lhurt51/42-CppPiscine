#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 120, 60, 5, 0) {
	std::cout << this->_name << ": The Ninja trap is here!"
		<< std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src) {
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << this->_name
		<< ": Ninja Trap down! I repeate Ninja Trap down!"
		<< std::endl;
	return;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_level = rhs.getLevel();
	}
	return *this;
}

void		NinjaTrap::ninjaShoeBox(NinjaTrap const &rhs) const {
	std::cout << this->_name << " uses ninja trap secret attack thru "
		<< rhs.getName() << ", dealing melee damage " << rhs.getMeleeDamage()
		<< " hp." << std::endl;
}

void		NinjaTrap::ninjaShoeBox(ScavTrap const &rhs) const {
	std::cout << this->_name << " uses scav trap thru "
		<< rhs.getName() << ", dealing " << rhs.getRangedDamage()
		<< " hp at range." << std::endl;
}

void		NinjaTrap::ninjaShoeBox(FragTrap const &rhs) const {
	std::cout << this->_name << " uses frag trap thru "
		<< rhs.getName() << ", dealing " << rhs.getRangedDamage()
		<< " hp at range." << std::endl;
}
