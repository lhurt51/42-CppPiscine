#include <iostream>
#include "Brain.hpp"
#include "Human.hpp"

int main() {
	Human brian;

	std::cout << brian.identify() << std::endl;
	std::cout << brian.getBrain().identify() << std::endl;
	return 0;
}
