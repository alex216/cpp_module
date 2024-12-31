#include <iostream>
#include <string>
#include <algorithm>

typedef char (*int2char)(int);

char toUpperChar(int c)
{
	return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void mytransform(
	std::string::iterator begin,
	std::string::iterator end,
	std::string::iterator d_begin,
	int2char op)
{
	for (; begin != end; ++begin)
	{
		*d_begin = op(*begin);
		++d_begin;
	}
	return;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];

			mytransform(
				arg.begin(),
				arg.end(),
				arg.begin(),
				toUpperChar);

			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return 0;
}
