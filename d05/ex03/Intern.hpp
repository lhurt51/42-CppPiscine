#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern {

public:

	Intern(void);
	Intern(Intern const &src);
	virtual ~Intern(void);

	Intern	&operator=(Intern const &rhs);

	Form	*makeForm(std::string type, std::string target) const;

	class			FormTypeNotFound : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

#endif
