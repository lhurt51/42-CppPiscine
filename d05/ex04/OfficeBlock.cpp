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

void			OfficeBlock::doBureaucracy(std::string action, std::string target) {
	Form *form;

	if (!this->_intern)
		throw OfficeBlock::InternNotAssigned();
	form = this->_intern->makeForm(action, target);
	if (!this->_signer)
		throw OfficeBlock::SignerNotAssigned();
	form->beSigned(*this->_signer);
	if (!this->_executor)
		throw OfficeBlock::ExecutorNotAssigned();
	this->_executor->executeForm(*form);
	delete form;
}

const char *OfficeBlock::InternNotAssigned::what() const throw() {
	return "Intern not assigned cannot make form";
}

const char *OfficeBlock::SignerNotAssigned::what() const throw() {
	return "Signer not assigned cannot sign form";
}

const char *OfficeBlock::ExecutorNotAssigned::what() const throw() {
	return "Executor not assigned cannot exec form";
}
