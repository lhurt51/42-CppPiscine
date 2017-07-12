#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat {

public:

	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &src);
	virtual	~Bureaucrat(void);

	Bureaucrat		&operator=(Bureaucrat const &rhs);
	Bureaucrat		operator++();
	Bureaucrat		operator++(int);
	Bureaucrat		operator--();
	Bureaucrat		operator--(int);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;
	void			incrementGrade(void);
	void			decrementGrade(void);
	void			executeForm(Form const &form);

	class			GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:

	std::string		_name;
	unsigned int	_grade;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif
