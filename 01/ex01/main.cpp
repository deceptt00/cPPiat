
#include "Zombie.hpp"

int	main() {
	Zombie	*horde = zombieHorde(5, "cyril");
	delete[] horde;
	return 0;
}