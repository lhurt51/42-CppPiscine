#include <iostream>
#include <string>
#include "Pony.hpp"

int	Pony::_nbPony = 0;

Pony::Pony(void) {
	Pony::_nbPony++;
	this->_ponyId = Pony::_nbPony;
	this->_age = 0;
	this->_size = "small";
	std::cout << "Pony #" << Pony::getPonyId() << " was born. He is " << this->getAge()
		<< " years old and " << this->getSize() << " in size" << std::endl;
}

Pony::~Pony(void) {
	Pony::_nbPony--;
	std::cout << "Pony #" << Pony::getPonyId() << " has died. He was " << this->getAge()
		<< " years old and " << this->getSize() << " in size" << std::endl;
}

int		Pony::getPonyId(void) {
	return this->_ponyId;
}

int		Pony::getAge(void) const {
	return this->_age;
}

std::string 	Pony::getSize(void) const {
	return this->_size;
}

void	Pony::growPony(int age) {
	if (age > 0) {
		this->_age += age;
		if (this->_age >= 5 && this->_age < 10)
			this->_size = "medium";
		else if (this->_age >= 10)
			this->_size = "large";
		else
			this->_size = "small";
		std::cout << "Pony #" << Pony::getPonyId() << " just grew. He is now " << this->getAge()
			<< " years old and now " << this->getSize() << " in size" << std::endl;
	} else {
		std::cout << "Enter valid age increment" << std::endl;
	}
}
