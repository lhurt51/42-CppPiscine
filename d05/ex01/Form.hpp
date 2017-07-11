#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form {

public:

	Form(std::string const name, unsigned int const reqGrade);
	Form(Form const &src);
	virtual	~Form(void);

	Form				&operator=(Form const &rhs);

	std::string const	getName(void) const;
	unsigned int		getReqGrade(void) const;
	bool				getBSigned(void) const;
	void 				beSigned(Bureaucrat &src);

	class			GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:

	std::string const	_name;
	unsigned int const	_reqGrade;
	bool				_bSigned;

};

std::ostream			&operator<<(std::ostream &o, Form const &i);

#endif
