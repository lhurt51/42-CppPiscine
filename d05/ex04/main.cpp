#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		try {
			ob.doBureaucracy("shrubbery creation", "backyard");
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 60);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		try {
			ob.doBureaucracy("robotomy request", "bender");
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 7);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 22);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);

		try {
			ob.doBureaucracy("presidential pardon", "mason");
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		hermes.incrementGrade();
		hermes.incrementGrade();
		hermes.incrementGrade();
		hermes.incrementGrade();

		try {
			ob.doBureaucracy("presidential pardon", "mason");
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
