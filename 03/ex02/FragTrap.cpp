
#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor" << std::endl;
}

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
		if (this->hitPoints <= 0) {
		std::cout << "FragTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (this->energyPoints > 0) {
		std::cout << "Fragtrap " << this->name << " asks : Who wants a high-five ?" << std::endl;
		this->energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << this->name << " doesn't have enough energy points !" << std::endl;
}