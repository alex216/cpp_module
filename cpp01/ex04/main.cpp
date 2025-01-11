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
		return (0);

	std::fstream r_file(filename);
	if (!r_file.is_open())
		std::cout << "r_file open error" << std::endl;

	std::string line, content;
	while (std::getline(r_file, line))
	{
		content += editline(line, s1, s2);
	}
	r_file.close();

	std::fstream w_file(filename);
	if (!w_file.is_open())
		std::cout << "w_file open error" << std::endl;

	w_file << content;
	w_file.close();
}
