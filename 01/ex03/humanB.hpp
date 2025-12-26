
#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(str name);
		~HumanB();
		
		void	attack() const;
		void	setWeapon(Weapon &weapon);
	private:
		str		name;
		Weapon	*weapon;
};

#endif