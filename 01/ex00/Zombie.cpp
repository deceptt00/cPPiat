

#include "Zombie.hpp"

Zombie::Zombie(str name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " died" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}