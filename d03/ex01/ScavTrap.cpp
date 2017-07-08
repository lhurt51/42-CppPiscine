#include <iostream>
#include <string>
#include "ScavTrap.hpp"

int const	ScavTrap::_maxHp = 100;
int const	ScavTrap::_maxEp = 50;
int const	ScavTrap::_meleeDamage = 30;
int const	ScavTrap::_rangedDamage = 20;
int const	ScavTrap::_armor = 5;

ScavTrap::ScavTrap(std::string name) : _name(name), _hp(ScavTrap::_maxHp), _ep(ScavTrap::_maxEp), _level(1) {
	std::cout << this->_name << ": Holy skagsack -- I’m INVISIBLE! gimme five."
		<< std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << this->_name
		<< ": Fatal errorrrrrrrrrrrrr…"
		<< std::endl;
	return;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_level = rhs.getLevel();
	}
	return *this;
}

std::string	ScavTrap::getName(void) const {
	return this->_name;
}

int			ScavTrap::getHp(void) const {
	return this->_hp;
}

int			ScavTrap::getEp(void) const {
	return this->_ep;
}

int			ScavTrap::getLevel(void) const {
	return this->_level;
}

void		ScavTrap::takeDamage(unsigned int amount) {
	unsigned int	total;

	total = (amount > ScavTrap::_armor) ? (amount - ScavTrap::_armor) : 0;
	this->_hp = (this->_hp - total > ScavTrap::_maxHp) ? 0 : (this->_hp -= total);
	std::cout << "SC4V-TP " << this->_name << " takes " << total
		<< " points of damage... his curent hp = " << this->_hp << std::endl;
	std::cout << this->_name
		<< ": Oh, SPHINCTERS! I’m so sorry Captain Flynt sir, please don’t burn me again..."
		<< std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount) {
	this->_hp = (this->_hp + amount > ScavTrap::_maxHp) ? ScavTrap::_maxHp : this->_hp += amount;
	std::cout << "SC4V-TP " << this->_name << " gets repaired " << amount
		<< " points of hp... his curent hp = " << this->_hp << std::endl;
	std::cout << this->_name
		<< ": You are looking FABULOOOOOOUS!"
		<< std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const &target) {
	typedef void (ScavTrap::*Actions)(std::string const & target);

	Actions actions[5] = {&ScavTrap::_snipe, &ScavTrap::_knifeAttack,
		&ScavTrap::_swordFight, &ScavTrap::_intimidate, &ScavTrap::_taunt};
	if (this->_ep != 0 && this->_ep - 10 < ScavTrap::_maxEp) {
		(this->*(actions[(rand()) % 5]))(target);
		this->_ep = (this->_ep - 10 > ScavTrap::_maxEp) ? 0 : (this->_ep -= 10);
	} else {
		std::cout << "SC4V-TP " << this->_name << " is out of energy"
			<< std::endl;
	}
}

void		ScavTrap::_snipe(std::string const &target) {
	std::cout << "SC4V-TP " << this->_name << " snipes " << target
		<< " from range, causing " << ScavTrap::_rangedDamage
		<< " points of damage!" << std::endl;
}

void		ScavTrap::_knifeAttack(std::string const &target) {
	std::cout << "SC4V-TP " << this->_name << " attacks " << target
		<< " with a knife, causing " << ScavTrap::_meleeDamage
		<< " points of damage!" << std::endl;
	std::cout << this->_name
		<< ": That’s right, Jack! I conquered your stairs! Prepare to feel the wrath of a CLAPTRAP WITH LEGS!"
		<< std::endl;
}

void		ScavTrap::_swordFight(std::string const &target) {
	std::cout << "SC4V-TP " << this->_name << " sword fights with " << target
		<< ", causing "
		<< ScavTrap::_meleeDamage + 5 << " points of damage!" << std::endl;
	std::cout << this->_name
		<< ": You thwacked that bullymong like a champ, minion!" << std::endl;
}

void		ScavTrap::_intimidate(std::string const &target) {
	std::cout << "SC4V-TP " << this->_name << " intimidates " << target
		<< ", causing " << target << " to run away in fear" << std::endl;
	std::cout << this->_name
		<< ": Intimdating, but slightly arousing. I like it." << std::endl;
}

void		ScavTrap::_taunt(std::string const &target) {
	std::cout << "SC4V-TP " << this->_name << " taunts " << target
		<< " into attacking his trap!" << std::endl;
	std::cout << this->_name
		<< ": You hear me, Jack?! You killed my friends! You destroyed my product line! I am the last Claptrap in existence, AND I AM GOING TO TEABAG YOUR CORPSE!"
		<< std::endl;
}
