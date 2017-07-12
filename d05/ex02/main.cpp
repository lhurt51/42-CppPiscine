#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		if (Bureaucrat *myCrat = new Bureaucrat("Mike", 90)) {
			std::cout << *myCrat << std::endl;
			ShrubberyCreationForm *creation = new ShrubberyCreationForm("Backyard");
			std::cout << *creation << std::endl;
			creation->execute(*myCrat);
			creation->beSigned(*myCrat);
			std::cout << *creation << std::endl;
			creation->execute(*myCrat);
			delete creation;
			delete myCrat;
		}
		if (Bureaucrat *signer = new Bureaucrat("Steve", 67)) {
			if (Bureaucrat *executor = new Bureaucrat("Joe", 42)) {
				RobotomyRequestForm *bender = new RobotomyRequestForm("Bender");
				std::cout << *bender << std::endl;
				bender->execute(*executor);
				bender->beSigned(*signer);
				std::cout << *bender << std::endl;
				bender->execute(*signer);
				bender->execute(*executor);
				bender->execute(*executor);
				bender->execute(*executor);
				bender->execute(*executor);
				delete bender;
				delete executor;
			}
			delete signer;
		}
		if (Bureaucrat *presSec = new Bureaucrat("Biden", 20)) {
			if (Bureaucrat *pres = new Bureaucrat("Obama", 2)) {
				PresidentialPardonForm *oliver = new PresidentialPardonForm("Oliver Queen");
				std::cout << *oliver << std::endl;
				pres->executeForm(*oliver);
				oliver->beSigned(*presSec);
				std::cout << *oliver << std::endl;
				presSec->executeForm(*oliver);
				pres->executeForm(*oliver);
				delete oliver;
				delete pres;
			}
			delete presSec;
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}
