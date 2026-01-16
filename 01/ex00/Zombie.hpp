
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

typedef std::string str;

class Zombie {
	public:
		Zombie(str name);
		~Zombie();

		void	announce();
		
	private:
		str	name;
};

Zombie* newZombie(str name);
void	randomChump(str name);

#endif