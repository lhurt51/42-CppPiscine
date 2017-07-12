#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src) {
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string				PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}

void					PresidentialPardonForm::_doExecution(void) const {
	std::cout << this->_target << " has been pardoned by Zafod Beedlebrox" << std::endl;
}
