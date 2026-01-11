
#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap() {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
	std::cout << "FragTrap " << this->name << " has been copied" << std::endl;

}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " was destroyed" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		this->hitPoints = rSym.getHitPoints();
		this->energyPoints = rSym.getEnergyPoints();
		this->attackDamage = rSym.getAttackDamage();
	}
	return *this;
}


void	FragTrap::highFivesGuys() {
	std::cout << "Fragtrap " << this->name << " asks : Who wants a high-five ?" << std::endl;
}