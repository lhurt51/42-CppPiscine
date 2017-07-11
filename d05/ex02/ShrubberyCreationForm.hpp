#ifndef SHRUBBERY_CREATION_FROM_HPP
# define SHRUBBERY_CREATION_FROM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	void				getTarget(void) const;


private:

	std::string			_target;
	virtual void		_doExecution(void);

};


#endif
