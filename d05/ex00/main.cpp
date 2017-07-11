#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		if (Bureaucrat *myCrat = new Bureaucrat("Mike", 90)) {
			std::cout << *myCrat << std::endl;
			std::cout << ++(*myCrat) << std::endl;
			std::cout << *myCrat << std::endl;
			std::cout << (*myCrat)++ << std::endl;
			std::cout << *myCrat << std::endl;
			std::cout << --(*myCrat) << std::endl;
			std::cout << *myCrat << std::endl;
			std::cout << (*myCrat)-- << std::endl;
			std::cout << *myCrat << std::endl;
			myCrat->incrementGrade();
			myCrat->incrementGrade();
			myCrat->incrementGrade();
			myCrat->incrementGrade();
			std::cout << *myCrat << std::endl;
			myCrat->decrementGrade();
			myCrat->decrementGrade();
			std::cout << *myCrat << std::endl;
		}
		if (Bureaucrat *myCrat1 = new Bureaucrat("Tim", 0)) {
			std::cout << *myCrat1 << std::endl;
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		if (Bureaucrat *myCrat2 = new Bureaucrat("Tom", 151)) {
			std::cout << *myCrat2 << std::endl;
		}
	}
	catch(Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}
