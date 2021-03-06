#include "Form.hpp"

Form::Form(std::string const name, unsigned int const reqGrade) : _name(name), _reqGrade(reqGrade), _bSigned(false) {
	if (reqGrade > 150) {
		throw Form::GradeTooLowException();
	} else if (reqGrade < 1) {
		throw Form::GradeTooHighException();
	}
	return;
}

Form::Form(Form const &src) : _name(src.getName()), _reqGrade(src.getReqGrade()) {
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

bool				Form::getBSigned(void) const {
	return this->_bSigned;
}

void 				Form::beSigned(Bureaucrat &src) {
	try {
		if (src.getGrade() > this->_reqGrade)
			throw Form::GradeTooLowException();
		else {
			this->_bSigned = true;
			std::cout << "Bureaucrat -> " << src.getName() << " signs Form -> " << this->_name << std::endl;
		}
	}
	catch (Form::GradeTooLowException& e) {
		std::cerr << "Bureaucrat -> " << src.getName() << " cannot sign Form -> " << this->_name << " because " << e.what() << std::endl;
	}
}

const char 			*Form::GradeTooHighException::what() const throw() {
	return "Form requires a grade limit less than 0";
}

const char 			*Form::GradeTooLowException::what() const throw() {
	return "Form requires a greater grade limit";
}

std::ostream		&operator<<(std::ostream &o, Form const &i) {
	o << i.getName() << " requires a grade of " << i.getReqGrade() << " and has " << (i.getBSigned() ? "been signed" : "not been signed");
	return o;
}
