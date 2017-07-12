#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) {
	return;
}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor) : _intern(&intern), _signer(&signer), _executor(&executor) {
	return;
}

OfficeBlock::OfficeBlock(OfficeBlock const &src) {
	*this = src;
	return;
}

OfficeBlock::~OfficeBlock(void) {
	if (this->_intern)
		delete this->_intern;
	if (this->_signer)
		delete this->_signer;
	if (this->_executor)
		delete this->_executor;
	return;
}

OfficeBlock		&OfficeBlock::operator=(OfficeBlock const &rhs) {
	if (this != &rhs) {
		this->_intern = rhs.getIntern();
		this->_signer = rhs.getSigner();
		this->_executor = rhs.getExecutor();
	}
	return *this;
}

Intern			*OfficeBlock::getIntern(void) const {
	return this->_intern;
}

Bureaucrat		*OfficeBlock::getSigner(void) const {
	return this->_signer;
}

Bureaucrat		*OfficeBlock::getExecutor(void) const {
	return this->_executor;
}

void			OfficeBlock::setIntern(Intern &in) {
	this->_intern = &in;
}

void			OfficeBlock::setSigner(Bureaucrat &signer) {
	this->_signer = &signer;
}

void			OfficeBlock::setExecutor(Bureaucrat &executor) {
	this->_executor = &executor;
}

void			doBureaucracy(std::string action, std::string target) {
	
}
