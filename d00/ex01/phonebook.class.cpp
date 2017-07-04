#include "main.hpp"
#include "phonebook.class.hpp"
#include "contact.class.hpp"

int		Phonebook::_nbInst = 0;

Phonebook::Phonebook( void ) : maxContacts(8) {
	Phonebook::_nbInst++;
	this->_contactCount = 0;
	return;
}

Phonebook::~Phonebook( void ) {
	Phonebook::_nbInst--;
	return;
}

int		Phonebook::getNbInst(void) {
	return Phonebook::_nbInst;
}

void	Phonebook::getContact( int index ) const {
	if (index >= 0 && index < this->maxContacts && index < this->_contactCount)
		this->_contacts[index].showContact();
	else
		std::cout << "Error: no contact with index - " << index << std::endl;
}

void	Phonebook::getAllContacts( void ) const {
	std::string	tmp;
	std::string::size_type sz;

	if (this->_contactCount == 0)
		std::cout << "Error: no contacts in the phonebook" << std::endl;
	for (int i = 0; i < this->_contactCount; i++) {
		this->_contacts[i].showContacts();
	}
	std::cout << "Enter the index of the person you want to search: ";
	while (std::getline(std::cin, tmp)) {
		if (tmp.compare("") == 0) {
			std::cout << "Please enter some input" << std::endl;
			std::cout << std::cout << "Enter the index of the person you want to search: ";
		} else
			break;
	}
	this->getContact(std::stoi(tmp, &sz) - 1);
}

void 	Phonebook::addContact( void ) {
	if (this->_contactCount < 8) {
		this->_contacts[this->_contactCount].startFilling();
		this->_contactCount++;
	}
	else
		std::cout << "Error: no more room for contacts" << std::endl;
}
