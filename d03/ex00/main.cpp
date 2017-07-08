#include <iostream>
#include "FragTrap.hpp"

int		main() {
	FragTrap	trap("claptrap");
	trap.vaulthunter_dot_exe("a hunter");
	trap.takeDamage(25);
	trap.beRepaired(5);
	trap.takeDamage(85);
	trap.vaulthunter_dot_exe("a wolf");
	trap.beRepaired(125);
	trap.takeDamage(150);
	trap.vaulthunter_dot_exe("a random");
	trap.beRepaired(100);
	trap.takeDamage(3);
	trap.vaulthunter_dot_exe("a wight");
	trap.vaulthunter_dot_exe("a tree");
	return 0;
}
