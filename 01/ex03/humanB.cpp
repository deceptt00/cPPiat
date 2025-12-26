
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(str name) : name(name) {
}

HumanB::~HumanB() {
	
}

void	HumanB::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}