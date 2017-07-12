#ifndef SHRUBBERY_CREATION_FROM_HPP
# define SHRUBBERY_CREATION_FROM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	std::string				getTarget(void) const;

protected:

	virtual void		_doExecution(void) const;

private:

	std::string					_target;
	static std::string const	_trees[4];
	void						_storeData(std::string &data, std::string fileName) const;

};


#endif
