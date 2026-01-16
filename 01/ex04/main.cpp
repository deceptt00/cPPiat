
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

typedef std::string str;

void	replace(std::string &line, std::string first, std::string second) {
	size_t	pos = 0;

	while ((pos = line.find(first, pos)) != std::string::npos) {
		line = line.substr(0, pos) + second + line.substr(pos + first.length());
		pos += second.size();
	}
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Usage : ./replace file string1 string2" << std::endl;
		return 0;
	}
	std::string		in_file = av[1];
	std::string		first = av[2];
	std::string		second = av[3];
	std::string		line;
	std::string		out_file = in_file + ".replace";
	std::ifstream	input(in_file.c_str());
	std::ofstream	output(out_file.c_str());
	if (input.is_open()) {
		while (std::getline(input, line)) {
			replace(line, first, second);
			output << line;
			if (!input.eof())
				output << std::endl;
		}
		input.close();
		output.close();
	}
	else
		std::cout << "Error: cannot open file." << std::endl;
	return 0;
}