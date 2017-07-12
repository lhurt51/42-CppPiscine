#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		if (Bureaucrat *myCrat = new Bureaucrat("Mike", 2)) {
			Intern	rando;
			Form	*randomFile;

			std::cout << *myCrat << std::endl;
			randomFile = rando.makeForm("shrubbery creation", "building");
			std::cout << *randomFile << std::endl;
			randomFile->execute(*myCrat);
			delete myCrat;
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}
