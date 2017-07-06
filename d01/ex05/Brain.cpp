#include <iostream>
#include <sstream>
#include <string>
#include "Brain.hpp"

Brain::Brain(void) {
	return;
}

Brain::~Brain(void) {
	return;
}

std::string	Brain::identify(void) const {
	std::stringstream strstrm;
	const void *addr = this;

	strstrm << addr;
	return strstrm.str();
}
