#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	void				getTarget(void) const;


private:

	std::string			_target;
	virtual void		_doExecution(void);

};

#endif
