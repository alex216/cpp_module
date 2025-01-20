#include <iostream>
#include <fstream>
#include <sstream>

__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q  mysed> /dev/null 2> /dev/null"))
		system("leaks -q mysed");
}

std::string editline(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::stringstream result;
	size_t pos;
	size_t start_pos = 0;

	while ((pos = line.find(s1, start_pos)) != std::string::npos)
	{
		result << line.substr(start_pos, pos - start_pos) << s2;
		start_pos = pos + s1.length();
	}
	result << line.substr(start_pos);
	return result.str();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::exit(42);
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: string1 cannot be empty" << std::endl;
		return 1;
	}

	// open read file
	std::ifstream r_file(filename);
	if (!r_file.is_open())
	{
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		r_file.close();
		return 1;
	}

	// open write file
	std::string outfile = filename + ".replace";
	std::ofstream w_file(outfile);
	if (!w_file.is_open())
	{
		std::cerr << "Error: cannot create output file: " << outfile << std::endl;
		r_file.close();
		return 1;
	}

	// replace and write
	std::string line;
	while (std::getline(r_file, line))
	{
		w_file << editline(line, s1, s2);
		if (!r_file.eof())
			w_file << '\n';
	}
	r_file.close();
	w_file.close();
	return 0;
}
