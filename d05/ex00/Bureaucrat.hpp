#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

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
	int				getGrade(void) const;
	void			incrementGrade(void);
	void			decrementGrade(void);

	class			GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Bureaucrat must be instanciated with a value less than 150";
		}
	};

	class			GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Bureaucrat must be instanciated with a value greater than 1";
		}
	};

private:

	std::string		_name;
	unsigned int	_grade;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif
