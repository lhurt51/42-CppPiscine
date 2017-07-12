#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	return;
}

Intern::Intern(Intern const &src) {
	*this = src;
	return;
}

Intern::~Intern(void) {
	return;
}

Intern	&Intern::operator=(Intern const &rhs) {
	if (this != &rhs) {};
	return *this;
}

Form	*Intern::makeForm(std::string type, std::string target) const {
	try {
		if (type.compare("shrubbery creation") == 0) {
			ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		} else if (type.compare("robotomy request") == 0) {
			RobotomyRequestForm *form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		} else if (type.compare("presidential pardon") == 0) {
			PresidentialPardonForm *form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		} else {
			throw Intern::FormTypeNotFound();
		}
	}
	catch (Intern::FormTypeNotFound &e) {
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

const char *Intern::FormTypeNotFound::what() const throw() {
	return "Form type didnt match any types that are present { shrubbery creation, robotomy request, presidential pardon }";
}
