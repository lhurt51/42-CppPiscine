#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade = grade;
	}
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	return;
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat		Bureaucrat::operator++() {
	if (this->_grade + 1 <= 150) {
		this->_grade++;
	}
	return *this;
}

Bureaucrat		Bureaucrat::operator++(int) {
	Bureaucrat	tmp(*this);
	if (this->_grade + 1 <= 150) {
		this->_grade++;
	}
	return tmp;
}

Bureaucrat		Bureaucrat::operator--() {
	if (this->_grade - 1 > 0) {
		this->_grade--;
	}
	return *this;
}

Bureaucrat		Bureaucrat::operator--(int) {
	Bureaucrat	tmp(*this);
	if (this->_grade - 1 > 0) {
		this->_grade--;
	}
	return tmp;
}

std::string		Bureaucrat::getName(void) const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void			Bureaucrat::incrementGrade(void) {
	--(*this);
}

void			Bureaucrat::decrementGrade(void) {
	++(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat requires a grade less than 0";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat requires a grade greater than 151";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << " -> Grade: " << i.getGrade();
	return o;
}
