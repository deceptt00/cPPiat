
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Scavtrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.getName()) {
	*this = src;
	std::cout << "ScavTrap " << this->name << " has been copied" << std::endl;

}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " was destroyed." << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		this->hitPoints = rSym.getHitPoints();
		this->energyPoints = rSym.getEnergyPoints();
		this->attackDamage = rSym.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->name << " doesn't have enough energy points !" << std::endl;
}

void	ScavTrap::guardGate() {
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead" << std::endl;
		return;
	}
	if (this->energyPoints > 0) {
		std::cout << "ScavTrap " << this->name << " enters guard guate "  << std::endl;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->name << " doesn't have enough energy points !" << std::endl;
}