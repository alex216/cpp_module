#include "ClapTrap.hpp"

static unsigned int ft_min(unsigned int a, unsigned int b)
{
	return (a < b ? a : b);
}

ClapTrap::ClapTrap(void) : _Name("Default")
{
	std::cout << this->_Name << "\tConstructed" << std::endl;
	this->_Hit_points = ClapTrap::ClapTrap_HEALTH_PTS;
	this->_Energy_points = ClapTrap::ClapTrap_ENERGY_PTS;
	this->_Attack_damage = ClapTrap::ClapTrap_ATTACK_DMG;
	ClapTrap::HEALTH_PTS = ClapTrap::ClapTrap_HEALTH_PTS;
	return;
}

ClapTrap::ClapTrap(const std::string name) : _Name(name)
{
	std::cout << this->_Name << "\tConstructed(with name)" << std::endl;
	this->_Hit_points = ClapTrap::ClapTrap_HEALTH_PTS;
	this->_Energy_points = ClapTrap::ClapTrap_ENERGY_PTS;
	this->_Attack_damage = ClapTrap::ClapTrap_ATTACK_DMG;
	ClapTrap::HEALTH_PTS = ClapTrap::ClapTrap_HEALTH_PTS;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this == &src)
		return *(this);
	this->_Name = src.getName();
	this->_Hit_points = ClapTrap::ClapTrap_HEALTH_PTS;
	this->_Energy_points = ClapTrap::ClapTrap_ENERGY_PTS;
	this->_Attack_damage = ClapTrap::ClapTrap_ATTACK_DMG;
	ClapTrap::HEALTH_PTS = ClapTrap::ClapTrap_HEALTH_PTS;
	return *(this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_Name << "\tDestructed💥" << std::endl;
	return;
}

// getter
std::string ClapTrap::getName(void) const
{
	return this->_Name;
}
unsigned int ClapTrap::getHit_points(void) const
{
	return this->_Hit_points;
}

unsigned int ClapTrap::getEnergy_points(void) const
{
	return this->_Energy_points;
}

unsigned int ClapTrap::getAttack_damage(void) const
{
	return this->_Attack_damage;
}

// setter
void ClapTrap::setHit_points(unsigned int amount)
{
	this->_Hit_points = amount;
}

void ClapTrap::setEnery_points(unsigned int amount)
{
	this->_Energy_points = amount;
}

// member functions
void ClapTrap::attack(const std::string &target)
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	std::cout << this->getName() << "\tattacks " << target << " with "
			  << this->getAttack_damage() << " damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHit_points() == 0)
		return;
	unsigned int hp = this->getHit_points();
	unsigned int damage;
	if (amount > hp)
		damage = hp;
	else
		damage = amount;
	this->setHit_points(hp - damage);
	std::cout << this->getName() << "\ttakes " << damage << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHit_points() == 0)
		return;
	unsigned int energy_pts = this->getEnergy_points();
	if (energy_pts == 0)
		return;
	this->setEnery_points(energy_pts - 1);

	unsigned int hp = this->getHit_points();
	unsigned int repaire = ft_min(amount, HEALTH_PTS - hp);
	this->setHit_points(hp + repaire);
	std::cout << this->getName() << "\trepaired " << repaire << " hp" << std::endl;
}
