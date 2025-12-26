
#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(str type) {
	this->type = type;
}

Weapon::~Weapon() {
	
}

const str	&Weapon::getType() const {
	return this->type;
}


void	Weapon::setType(str ntype) {
	this->type = ntype;
}