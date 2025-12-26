
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

typedef std::string str;

class Zombie {
	public:
		Zombie(str name);
		~Zombie();

		Zombie* newZombie(str name);
		void	randomChump(str name);
	private:
		void	announce();
		str	name;
};


#endif