#include "main.hpp"
#include "phonebook.class.hpp"

Phonebook::Phonebook( char p1, int p2, float p3, float f ) : a1(p1), a2(p2), a3(p3), pi(f), pd(42) {
	std::cout << "Constructor called" << std::endl;
	Phonebook::_nbInst++;

	this->publicFoo = 0;
	std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Destructor called" << std::endl;
	Phonebook::_nbInst--;
	return;
}

void	Phonebook::bar(void) const {
	std::cout << "Member function bar called" << std::endl;
	std::cout << "this->foo: " << this->foo << std::endl;
	std::cout << "this->a1: " << this->a1 << std::endl;
	std::cout << "this->a2: " << this->a2 << std::endl;
	std::cout << "this->a3: " << this->a3 << std::endl;
	std::cout << "this->pi: " << this->pi << std::endl;
	std::cout << "this->pd: " << this->pd << std::endl;

	return;
}

void	Phonebook::publicBar(void) const {
	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Phonebook::_privateBar(void) const {
	std::cout << "Member function _privateBar called" << std::endl;
	return;
}

int		Phonebook::getPrivateFoo(void) const {
	return this->_privateFoo;
}

void	Phonebook::setPrivateFoo(int val) {
	if (val >= 0)
		this->_privateFoo = val;
	return;
}

int		Phonebook::compare(Phonebook * other) const {
	if (this->_privateFoo < other->getPrivateFoo())
		return -1;
	else if (this->_privateFoo > other->getPrivateFoo())
		return 1;
	else
		return 0;
}

int		Phonebook::getNbInst(void) {
	return Phonebook::_nbInst;
}

int		Phonebook::_nbInst = 0;
