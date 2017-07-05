#include <iostream>
#include <string>

int		main() {
	std::string		myString = "HI THIS IS BRAIN";

	std::string*	stringPtr = &myString;
	std::string&	stringRef = myString;

	std::cout << "The pointed string -> " << *stringPtr << std::endl;
	std::cout << "The referenced string -> " << stringRef << std::endl;
}
