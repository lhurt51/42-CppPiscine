#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main() {
	ZombieEvent cool;
	int			randomNum;

	cool.randomChump();
	cool.setZombieType("fast");
	randomNum = rand() % 10;
	for (int i = 0; i < randomNum; i++)
		cool.randomChump();
	cool.setZombieType("fat");
	randomNum = rand() % 10;
	for (int i = 0; i < randomNum; i++)
		cool.randomChump();
	cool.setZombieType("quick");
	randomNum = rand() % 10;
	for (int i = 0; i < randomNum; i++)
		cool.randomChump();
	cool.setZombieType("slow");
	randomNum = rand() % 10;
	for (int i = 0; i < randomNum; i++)
		cool.randomChump();
}
