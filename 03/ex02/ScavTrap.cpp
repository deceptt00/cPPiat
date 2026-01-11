
#include "ScavTrap.hpp"

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
	std::cout << "ScavTrap " << this->name << " attacks " << target << " dealing " << this->attackDamage << " attack damage" << std::endl;
}

void	ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << this->name << " uses Guard Gate" << std::endl;
}