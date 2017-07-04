#include "main.hpp"
#include "phonebook.class.hpp"

std::string	ret_upper(std::string str) {
	std::locale loc;
	std::string rtn;

	for (std::string::size_type i = 0; i < str.length(); i++) {
		rtn += std::toupper(str[i], loc);
	}
	return rtn;
}

int		main() {
	Phonebook	list;
	std::string	tmp;

	while (std::getline(std::cin, tmp)) {
		tmp = ret_upper(tmp);
		if (tmp.compare("EXIT") == 0) {
			break;
		} else if (tmp.compare("ADD") == 0) {
			list.addContact();
		} else if (tmp.compare("SEARCH") == 0) {
			list.getAllContacts();
		}
	}

	return 0;
}
