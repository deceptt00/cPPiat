
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

typedef std::string str;

class Weapon {
	public:
		Weapon();
		Weapon(str type);
		~Weapon();

		const str	&getType() const;
		void		setType(str ntype);
	private:
		str	type;
};

#endif