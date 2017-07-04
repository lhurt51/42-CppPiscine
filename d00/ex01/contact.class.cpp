#include "main.hpp"
#include "contact.class.hpp"

int		Contact::_nbInst = 0;

Contact::Contact(void) {
	Contact::_nbInst++;
	return;
}

Contact::~Contact(void) {
	Contact::_nbInst--;
	return;
}

int		Contact::getNbInst() {
	return Contact::_nbInst;
}

void	Contact::showContact( void ) const {
	std::cout << std::setw(10) << this->_truncateInput("first name") << "|"
		<< std::setw(10) << this->_truncateInput(this->_firstName) << std::endl;
	std::cout << std::setw(10) << this->_truncateInput("last name") << "|"
		<< std::setw(10) << this->_truncateInput(this->_lastName) << std::endl;
	std::cout << std::setw(10) << this->_truncateInput("nickname") << "|"
		<< std::setw(10) << this->_truncateInput(this->_nickname) << std::endl;
	std::cout << std::setw(10) << this->_truncateInput("login") << "|"
		<< std::setw(10) << this->_truncateInput(this->_login) << std::endl;
	std::cout << std::setw(10) << this->_truncateInput("address") << "|"
		<< std::setw(10) << this->_truncateInput(this->_postalAddress)
		<< std::endl;
	std::cout << std::setw(10) << this->_truncateInput("phone #") << "|"
		<< std::setw(10) << this->_truncateInput(this->_phoneNumber)
		<< std::endl;
	std::cout << std::setw(10) << this->_truncateInput("birthdate") << "|"
		<< std::setw(10) << this->_truncateInput(this->_birthDate) << std::endl;
	std::cout << std::setw(10) << this->_truncateInput("fav meal") << "|"
		<< std::setw(10) << this->_truncateInput(this->_favoriteMeal)
		<< std::endl;
	std::cout << std::setw(10) << this->_truncateInput("color") << "|"
		<< std::setw(10) << this->_truncateInput(this->_underwearColor)
		<< std::endl;
	std::cout << std::setw(10) << this->_truncateInput("secret") << "|"
		<< std::setw(10) << this->_truncateInput(this->_darkestSecret)
		<< std::endl;
}

void	Contact::showContacts( void ) const {
	std::cout << std::setw(10) << this->_truncateInput(this->_firstName) << "|"
		<< std::setw(10) << this->_truncateInput(this->_lastName) << "|"
		<< std::setw(10) << this->_truncateInput(this->_nickname) << std::endl;
}

void	Contact::startFilling( void ) {
	if (this->_firstName.empty())
		this->_setContact();
}

void	Contact::_setContact( void ) {
	this->_firstName = this->_recieveInput("Enter your first name ---> ");
	this->_lastName = this->_recieveInput("Enter your last name ---> ");
	this->_nickname = this->_recieveInput("Enter your nickname ---> ");
	this->_login = this->_recieveInput("Enter your login ---> ");
	this->_postalAddress = this->_recieveInput("Enter your postal address ---> ");
	this->_phoneNumber = this->_recieveInput("Enter your phone number ---> ");
	this->_birthDate = this->_recieveInput("Enter your birthdate ---> ");
	this->_favoriteMeal = this->_recieveInput("Enter your favorite meal ---> ");
	this->_underwearColor = this->_recieveInput("Enter your underwear color ---> ");
	this->_darkestSecret = this->_recieveInput("Enter your darkest secret ---> ");
}

std::string	Contact::_recieveInput( std::string msg ) const {
	std::string tmp;

	std::cout << msg;
	while (std::getline(std::cin, tmp)) {
		if (tmp.compare("") == 0) {
			std::cout << "Please enter some input" << std::endl;
			std::cout << msg;
		} else
			break;
	}
	return tmp;
}

std::string	Contact::_truncateInput( std::string in ) const {
	std::string	rtn;

	rtn = in;
	if (in.length() > 10) {
		rtn = rtn.substr(0, 9);
		rtn.append(".");
	}
	return rtn;
}
