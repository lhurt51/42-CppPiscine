#include <iostream>
#include <locale>

void	ret_upper(char *str) {
	std::locale loc;

	for (unsigned i = 0; i < (unsigned)strlen(str); i++) {
		std::cout << std::toupper(str[i], loc);
	}
}

int 	main(int argc, char *argv[]) {
	if (argc > 1) {
		for (int i = 0; i < argc - 1; i++) {ret_upper(argv[i + 1]);}
		std::cout << std::endl;
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}
