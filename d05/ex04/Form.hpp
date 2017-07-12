#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class Form {

public:

	Form(std::string const name, unsigned int const reqGrade, unsigned int const reqExecut);
	Form(Form const &src);
	virtual	~Form(void);

	Form				&operator=(Form const &rhs);

	std::string const	getName(void) const;
	unsigned int		getReqGrade(void) const;
	unsigned int		getReqExecut(void) const;
	bool				getBSigned(void) const;
	void 				beSigned(Bureaucrat const &src);
	void				execute(Bureaucrat const &src) const;

	class			GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

protected:

	virtual void		_doExecution(void) const = 0;

private:

	std::string const	_name;
	unsigned int const	_reqGrade;
	unsigned int const	_reqExecut;
	bool				_bSigned;

};

std::ostream			&operator<<(std::ostream &o, Form const &i);

#endif
