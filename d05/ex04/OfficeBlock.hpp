#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock {

public:

	OfficeBlock(void);
	OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
	OfficeBlock(OfficeBlock const &src);
	virtual		~OfficeBlock(void);

	OfficeBlock		&operator=(OfficeBlock const &rhs);

	Intern			*getIntern(void) const;
	Bureaucrat		*getSigner(void) const;
	Bureaucrat		*getExecutor(void) const;
	void			setIntern(Intern &in);
	void			setSigner(Bureaucrat &signer);
	void			setExecutor(Bureaucrat &executor);
	void			doBureaucracy(std::string action, std::string target);

	class			InternNotAssigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			SignerNotAssigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class			ExecutorNotAssigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:

	Intern		*_intern;
	Bureaucrat	*_signer;
	Bureaucrat	*_executor;

};

#endif
