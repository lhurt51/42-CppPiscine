#include <iostream>
#include <string>
#include "Human.hpp"

void	Human::action(std::string const & action_name, std::string const & target) {
	typedef void (Human::*Actions)(std::string const & target);
	std::string const actionStr[] = { "melee", "ranged", "intimidating shout" };

	Actions actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	for (int i = 0; i < 3; i++) {
		if (actionStr[i] == action_name) {
			(this->*(actions[i]))(target);
			break;
		}
	}
}

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Melee attacks the target -> " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "Fires ranged attacks at the target -> " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Shouts intimidatingly at the target -> " << target << std::endl;
}
