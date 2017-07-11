#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade < 1) {
		throw Bureaucrat::GradeTooLowException();
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

int				Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void			Bureaucrat::incrementGrade(void) {
	--(*this);
}

void			Bureaucrat::decrementGrade(void) {
	++(*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i) {
	o << i.getName() << " -> Grade: " << i.getGrade();
	return o;
}
