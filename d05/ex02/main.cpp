#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		if (Bureaucrat *myCrat = new Bureaucrat("Mike", 90)) {
			std::cout << *myCrat << std::endl;
			delete myCrat;
			if (Form *broke = new Form("QWERT-2", 100, 151)) {
				std::cout << *broke << std::endl;
				delete broke;
			}
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		if (Form *myForm1 = new Form("DW3R-45", 50, 0)) {
			std::cout << *myForm1 << std::endl;
			delete myForm1;
		}
	}
	catch(Form::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}
