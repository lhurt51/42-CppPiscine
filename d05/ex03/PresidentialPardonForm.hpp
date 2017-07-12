#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	std::string				getTarget(void) const;

protected:

	virtual void		_doExecution(void) const;

private:

	std::string			_target;

};

#endif
