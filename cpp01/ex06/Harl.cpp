#include <iostream>

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	std::cout << "Destructed💥" << std::endl;
	return;
}

void Harl::complain(std::string level)
{
	const std::string HarlLevelsList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlFuncPtr HarlFuncList[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == HarlLevelsList[i])
		{
			(this->*HarlFuncList[i])();
			return;
		}
	}
	return;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
}
