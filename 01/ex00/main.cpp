
#include "Zombie.hpp"

int	main() {
	Zombie	*z = newZombie("ZOM");

	z->announce();
	randomChump("bie");
	delete z;
}