#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 30, 20, 5) {
	std::cout << this->_name << ": Holy skagsack -- I’m INVISIBLE! gimme five."
		<< std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
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
