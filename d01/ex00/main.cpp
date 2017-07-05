#include <iostream>
#include <string>
#include "Pony.hpp"

void	ponyOnTheStack(void) {
	Pony second = Pony();

	second.growPony(2);
	second.growPony(3);
}

void	ponyOnTheHeap(void) {
	Pony* first = new Pony();

	first->growPony(3);
	first->growPony(5);
	ponyOnTheStack();
	first->growPony(4);
	delete first;
}

int		main() {
	ponyOnTheHeap();
	return 0;
}
