#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main() {
	ZombieHorde lotsOfZombies = ZombieHorde(15);
	lotsOfZombies.announce();
}
