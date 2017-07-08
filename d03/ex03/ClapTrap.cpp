#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, unsigned int maxHp, unsigned int maxEp, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armor) : _name(name), _hp(maxHp), _ep(maxEp), _level(1), _maxHp(maxHp), _maxEp(maxEp), _meleeDamage(meleeDamage), _rangedDamage(rangedDamage), _armor(armor) {
	std::cout << this->_name << " was born!"
		<< std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _maxHp(src.getMaxHp()), _maxEp(src.getMaxEp()), _meleeDamage(src.getMeleeDamage()), _rangedDamage(src.getRangedDamage()), _armor(src.getArmor()) {
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->_name << " has died" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_level = rhs.getLevel();
	}
	return *this;
}

std::string		ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int	ClapTrap::getHp(void) const {
	return this->_hp;
}

unsigned int	ClapTrap::getEp(void) const {
	return this->_ep;
}

unsigned int	ClapTrap::getLevel(void) const {
	return this->_level;
}

unsigned int	ClapTrap::getMaxHp(void) const {
	return this->_maxHp;
}

unsigned int	ClapTrap::getMaxEp(void) const {
	return this->_maxEp;
}

unsigned int	ClapTrap::getMeleeDamage(void) const {
	return this->_meleeDamage;
}

unsigned int	ClapTrap::getRangedDamage(void) const {
	return this->_rangedDamage;
}

unsigned int	ClapTrap::getArmor(void) const {
	return this->_armor;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	total;

	total = (amount > ClapTrap::_armor) ? (amount - ClapTrap::_armor) : 0;
	this->_hp = (this->_hp - total > ClapTrap::_maxHp) ? 0 : (this->_hp -= total);
	std::cout << this->_name << " takes " << total
		<< " points of damage... his curent hp = " << this->_hp << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	this->_hp = (this->_hp + amount > ClapTrap::_maxHp) ? ClapTrap::_maxHp : this->_hp += amount;
	std::cout << this->_name << " gets repaired " << amount
		<< " points of hp... his curent hp = " << this->_hp << std::endl;
}
