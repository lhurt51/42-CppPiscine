#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	std::string			getTarget(void) const;

protected:

	virtual void		_doExecution(void) const;

private:

	std::string			_target;

};

#endif
