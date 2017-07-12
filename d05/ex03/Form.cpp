#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, unsigned int const reqGrade, unsigned int const reqExecut) : _name(name), _reqGrade(reqGrade), _reqExecut(reqExecut), _bSigned(false) {
	if (reqGrade > 150 || reqExecut > 150) {
		throw Form::GradeTooLowException();
	} else if (reqGrade < 1 || reqExecut < 1) {
		throw Form::GradeTooHighException();
	}
	return;
}

Form::Form(Form const &src) : _name(src.getName()), _reqGrade(src.getReqGrade()), _reqExecut(src.getReqExecut()) {
	*this = src;
	return;
}

Form::~Form(void) {
	return;
}

Form				&Form::operator=(Form const &rhs) {
	if (this != &rhs) {
		this->_bSigned = rhs.getBSigned();
	}
	return *this;
}

std::string const	Form::getName(void) const {
	return this->_name;
}

unsigned int		Form::getReqGrade(void) const {
	return this->_reqGrade;
}

unsigned int		Form::getReqExecut(void) const {
	return this->_reqExecut;
}

bool				Form::getBSigned(void) const {
	return this->_bSigned;
}

void 				Form::beSigned(Bureaucrat const &src) {
	try {
		if (src.getGrade() > this->_reqGrade)
			throw Form::GradeTooLowException();
		else {
			this->_bSigned = true;
			std::cout << "Bureaucrat -> " << src.getName() << " signs Form -> " << this->_name << std::endl;
		}
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << "Bureaucrat -> " << src.getName() << " cannot sign Form -> " << this->_name << " because " << e.what() << ": " << this->_reqGrade << std::endl;
	}
}

void				Form::execute(Bureaucrat const &src) const {
	try {
		if (src.getGrade() > this->_reqExecut)
			throw Form::GradeTooLowException();
		else if (!this->_bSigned)
			throw Form::FormNotSignedException();
		else {
			this->_doExecution();
			std::cout << "Bureaucrat -> " << src.getName() << " exec Form -> " << this->_name << std::endl;
		}
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << "Bureaucrat -> " << src.getName() << " cannot exec Form -> " << this->_name << " because " << e.what() << ": " << this->_reqExecut << std::endl;
	}
	catch (Form::FormNotSignedException& e) {
		std::cerr << "Bureaucrat -> " << src.getName() << " cannot exec Form -> " << this->_name << " because " << e.what() << std::endl;
	}
}

const char 			*Form::GradeTooHighException::what() const throw() {
	return "Form requires a grade limit less than 0";
}

const char 			*Form::GradeTooLowException::what() const throw() {
	return "Form requires a greater grade limit";
}

const char 			*Form::FormNotSignedException::what() const throw() {
	return "Form needs to be signed to exec";
}

std::ostream		&operator<<(std::ostream &o, Form const &i) {
	o << i.getName() << " requires a grade of " << i.getReqGrade() << " to sign, a grade of " <<  i.getReqExecut() << " to execute, and has " << (i.getBSigned() ? "been signed" : "not been signed");
	return o;
}
