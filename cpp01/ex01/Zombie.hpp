#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie(void);
	Zombie(const std::string &name);
	~Zombie(void);

	void announce(void);

	// ex01
	void setName(const std::string &name);

private:
	std::string name;
};

#endif
