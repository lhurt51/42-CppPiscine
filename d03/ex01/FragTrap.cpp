#include <iostream>
#include <string>
#include "FragTrap.hpp"

int const	FragTrap::_maxHp = 100;
int const	FragTrap::_maxEp = 100;
int const	FragTrap::_meleeDamage = 30;
int const	FragTrap::_rangedDamage = 20;
int const	FragTrap::_armor = 5;

FragTrap::FragTrap(std::string name) : _name(name), _hp(FragTrap::_maxHp), _ep(FragTrap::_maxEp), _level(1) {
	std::cout << this->_name << ": Badasses incoming! Annnnndddddd ... OPEN!"
		<< std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) {
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
	std::cout << this->_name
		<< ": Ouch! Crap on a cracker!"
		<< std::endl;
}

void		FragTrap::beRepaired(unsigned int amount) {
	this->_hp = (this->_hp + amount > FragTrap::_maxHp) ? FragTrap::_maxHp : this->_hp += amount;
	std::cout << "FR4G-TP " << this->_name << " gets repaired " << amount
		<< " points of hp... his curent hp = " << this->_hp << std::endl;
	std::cout << this->_name
		<< ": LET'S TEAR THIS PLANET A NEW ASSHOLE! YAAAAAAGHHHHH!"
		<< std::endl;
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
