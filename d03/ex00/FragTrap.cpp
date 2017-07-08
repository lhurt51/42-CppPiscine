#include <iostream>
#include <string>
#include "FragTrap.hpp"

int const	FragTrap::_maxHp = 100;
int const	FragTrap::_maxEp = 100;
int const	FragTrap::_meleeDamage = 30;
int const	FragTrap::_rangedDamage = 20;
int const	FragTrap::_armor = 5;

FragTrap::FragTrap(std::string name) : _name(name), _hp(100), _ep(100), _level(1) {
	std::cout << this->_name << ": Annnnndddddd ... OPEN!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << this->_name << ": NOOOOOOOOOOOOOOOOO! DAMN YOU, STAIRS! DAMN YOU TO HELL!" << std::endl;
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

std::string	FragTrap::getName(void) const {
	return this->_name;
}

int			FragTrap::getHp(void) const {
	return this->_hp;
}

int			FragTrap::getEp(void) const {
	return this->_ep;
}

int			FragTrap::getLevel(void) const {
	return this->_level;
}

void		FragTrap::takeDamage(unsigned int amount) {
	unsigned int	total;

	total = (amount > FragTrap::_armor) ? (amount - FragTrap::_armor) : 0;
	this->_hp = (this->_hp - total > FragTrap::_maxHp) ? 0 : (this->_hp -= total);
	std::cout << "FR4G-TP " << this->_name << " takes " << total
		<< " points of damage... his curent hp = " << this->_hp << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount) {
	this->_hp = (this->_hp + amount > FragTrap::_maxHp) ? FragTrap::_maxHp : this->_hp += amount;
	std::cout << "FR4G-TP " << this->_name << " gets repaired " << amount
		<< " points of hp... his curent hp = " << this->_hp << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target) {
	typedef void (FragTrap::*Actions)(std::string const & target);

	Actions actions[2] = {&FragTrap::_meleeAttack, &FragTrap::_rangedAttack};
	if (this->_ep != 0 && this->_ep - 25 < FragTrap::_maxEp) {
		(this->*(actions[rand() % 2]))(target);
		this->_ep = (this->_ep - 25 > FragTrap::_maxEp) ? 0 : (this->_ep -= 25);
	} else {
		std::cout << "FR4G-TP " << this->_name << " is out of energy" << std::endl;
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
}
