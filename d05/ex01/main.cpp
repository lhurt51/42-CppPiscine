#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		if (Bureaucrat *myCrat = new Bureaucrat("Mike", 90)) {
			std::cout << *myCrat << std::endl;
			if (Form *myForm = new Form("TDR-32", 50)) {
				std::cout << *myForm << std::endl;
				myForm->beSigned(*myCrat);
				for (int i = 0; i < 42; i++)
					myCrat->incrementGrade();
				std::cout << *myCrat << std::endl;
				myForm->beSigned(*myCrat);
				std::cout << *myForm << std::endl;
				delete myForm;
			}
			delete myCrat;
			if (Form *broke = new Form("QWERT-2", 151)) {
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
		if (Form *myForm1 = new Form("DW3R-45", 0)) {
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
