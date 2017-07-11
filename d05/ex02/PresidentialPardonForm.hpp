#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	void				getTarget(void) const;


private:

	std::string			_target;
	virtual void		_doExecution(void);

};

#endif
