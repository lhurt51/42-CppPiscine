#include <fstream>
#include <iostream>
#include <string>

std::string	readData(std::string fileName) {
	int				i;
	std::ifstream	infile;
	std::string		tmp;
	std::string		rtn;

	i = 0;
	infile.open(fileName);
	while (std::getline(infile, tmp)){
		if (i++ != 0)
			tmp.insert(0, 1, '\n');
		rtn += tmp;
	}
	infile.close();
	return rtn;
}

void		replaceAllWords(std::string &data, std::string from, std::string to) {
	size_t start_pos;

	if (!from.empty()){
		start_pos = 0;
		while ((start_pos = data.find(from, start_pos)) != std::string::npos) {
			data.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}
}

void		storeData(std::string &data, std::string fileName) {
	std::ofstream	outfile;

	outfile.open(fileName += ".replace");
	outfile << data << std::endl;
	outfile.close();
}

int 		main(int argc, char const *argv[]) {
	std::string	data;

	if (argc == 4) {
		data = readData(argv[1]);
		if (!data.empty()) {
			replaceAllWords(data, argv[2], argv[3]);
			storeData(data, argv[1]);
		} else {
			std::cout << "File is empty" << std::endl;
		}
	} else {
		std::cout << "Usage: ./replace FILENAME (STRING TO BE REPLACED) (STRING TO REPLACE WITH)" << std::endl;
	}
	return 0;
}
