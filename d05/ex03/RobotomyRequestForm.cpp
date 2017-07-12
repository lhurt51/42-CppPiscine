#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) {
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string			RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

void				RobotomyRequestForm::_doExecution(void) const {
	std::cout << '\7' << this->_target << ((rand() % 2) ? " has been robotomized successfully!" : " has been injured in the failed robotomy") << std::endl;
}
