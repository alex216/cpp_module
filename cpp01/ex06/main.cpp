#include <cstdlib>

#include "Harl.hpp"

#define NUM 4

enum
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::exit(42);

	std::string orderArr[NUM] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (orderArr[i] == argv[1])
			break;
	}
	if (i == NUM)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	Harl harl;
	switch (i)
	{
	case DEBUG:
		harl.complain("DEBUG");
	case INFO:
		harl.complain("INFO");
	case WARNING:
		harl.complain("WARNING");
	case ERROR:
		harl.complain("ERROR");
	default:
		break;
	}
}
