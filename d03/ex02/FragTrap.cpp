#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30, 20, 5) {
	std::cout << this->_name << ": Badasses incoming! Annnnndddddd ... OPEN!"
		<< std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	*this = src;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << this->_name
		<< ": NOOOOOOOOOOOOOOOOO! DAMN YOU, STAIRS! DAMN YOU TO HELL!"
		<< std::endl;
	return;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_level = rhs.getLevel();
	}
	return *this;
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target) {
	typedef void (FragTrap::*Actions)(std::string const & target);

	Actions actions[7] = {&FragTrap::_meleeAttack, &FragTrap::_rangedAttack,
		&FragTrap::_explosiveAttack, &FragTrap::_spinningRangedAttack,
		&FragTrap::_spinningMeleeAttack, &FragTrap::_spinningExplosiveAttack,
		&FragTrap::_cries};
	if (this->_ep != 0 && this->_ep - 25 < FragTrap::_maxEp) {
		(this->*(actions[(rand()) % 7]))(target);
		this->_ep = (this->_ep - 25 > FragTrap::_maxEp) ? 0 : (this->_ep -= 25);
	} else {
		std::cout << "FR4G-TP " << this->_name << " is out of energy"
			<< std::endl;
	}
}

void		FragTrap::_rangedAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << FragTrap::_rangedDamage
		<< " points of damage!" << std::endl;
}

void		FragTrap::_meleeAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " melee attacks " << target
		<< ", causing " << FragTrap::_meleeDamage << " points of damage!"
		<< std::endl;
	std::cout << this->_name
		<< ": You're fighting something, aren't you? I can tell -- I have very acute hearing!"
		<< std::endl;
}

void		FragTrap::_explosiveAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " with explosives, causing "
		<< FragTrap::_meleeDamage + FragTrap::_rangedDamage
		<< " points of damage!" << std::endl;
	std::cout << this->_name
		<< ": Oh. He, uh, just exploded, didn't he? I guess that's kinda like dancing."
		<< std::endl;
}

void		FragTrap::_spinningRangedAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " spinning at range, causing " << FragTrap::_rangedDamage * 1.5
		<< " points of damage!" << std::endl;
}

void		FragTrap::_spinningMeleeAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " spinning melee attacks "
		<< target << ", causing " << FragTrap::_meleeDamage * 1.5
		<< " points of damage!" << std::endl;
}

void		FragTrap::_spinningExplosiveAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " spinning with explosives, causing "
		<< (FragTrap::_meleeDamage + FragTrap::_rangedDamage) * 1.5
		<< " points of damage!" << std::endl;
}

void		FragTrap::_cries(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " but starts crying, causing 0 points of damage!" << std::endl;
	std::cout << this->_name
		<< ": What's going on?! Should I be scared?"
		<< std::endl;
}
