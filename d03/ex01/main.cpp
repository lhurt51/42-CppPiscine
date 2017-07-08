#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	ScavTrap	scav("clapscav");
	scav.challengeNewcomer("a zobie");
	scav.takeDamage(25);
	scav.beRepaired(5);
	scav.takeDamage(85);
	scav.challengeNewcomer("a bear");
	scav.beRepaired(125);
	scav.takeDamage(150);
	scav.challengeNewcomer("a random");
	scav.beRepaired(100);
	scav.takeDamage(3);
	scav.challengeNewcomer("a ghost");
	scav.challengeNewcomer("a tree");
	return 0;
}
