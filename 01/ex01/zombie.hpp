
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

typedef std::string str;

class Zombie {
	public:
		Zombie();
		~Zombie();

		void			setName(str name);
		void			announce() const;

	private:
		str		name;
};

Zombie	*zombieHorde(int n, str name);

#endif