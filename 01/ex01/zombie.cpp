
#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Be careful ! a new zombie is in the house !" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "A zombie died a second time." << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(str name) {
	this->name = name;
}