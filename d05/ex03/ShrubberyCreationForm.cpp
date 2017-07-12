#include "ShrubberyCreationForm.hpp"

std::string const	ShrubberyCreationForm::_trees[4] = { "         \\/ |    |/\n        \\/ / \\||/  /_/___/_\n         \\/   |/ \\/\n    _\\__\\_\\   |  /_____/_\n           \\  | /          /\n  __ _-----`  |{,-----------~\n            \\ }{\n			}{{\n             }}{\n             {{}\n       , -=-~{ .-^- _\n        	 `}\n              {\n",
 	"              v .   ._, |_  .,\n           `-._\\/  .  \\ /    |/_\n               \\\\  _\\, y | \\//\n         _\\_.___\\\\, \\\\/ -.\\||\n           `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'\n                     |    |//\n                     |_    /\n                     |-   |\n                     |   =|\n                     |    |\n--------------------/ ,  . \\--------._\n",
	"       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{\n",
	"         &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%' & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n" };

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src) {
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string				ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

void					ShrubberyCreationForm::_doExecution(void) const {
	std::string	tmp;

	for (int i = 0; i < rand() % 10; i++) {
		tmp += ShrubberyCreationForm::_trees[rand() % 4] + "\n\n";
	}
	this->_storeData(tmp, this->_target);
}

void					ShrubberyCreationForm::_storeData(std::string &data, std::string fileName) const {
	std::ofstream	outfile;

	outfile.open(fileName += "_shrubbery");
	outfile << data << std::endl;
	outfile.close();
}
