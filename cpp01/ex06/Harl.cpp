#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
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
	std::cout << "debug" << std::endl;
}
void Harl::info(void)
{
	std::cout << "info" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}
void Harl::error(void)
{
	std::cout << "error" << std::endl;
}
