
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	Clapy("Clapy");
	ClapTrap	*Trapy = new ClapTrap("Roméo");
	ScavTrap	Cyril("Cyril");

	Clapy.attack("Cyril");
	Cyril.takeDamage(Clapy.getAttackDamage());
	Cyril.beRepaired(18);
	Cyril.guardGate();
	Cyril.attack("Trapy");
	Trapy->takeDamage(Cyril.getAttackDamage());
	delete Trapy;
	return 0;
}

// #include "ScavTrap.hpp"

// int main()
// {
//     ScavTrap s("GateKeeper");

//     s.attack("enemy");
//     s.takeDamage(20);
//     s.beRepaired(10);
//     s.guardGate();
// }

// #include "ScavTrap.hpp"

// int main()
// {
//     ClapTrap *ptr = new ScavTrap("Polymorph");

//     ptr->attack("target");   // must call ClapTrap::attack unless virtual
//     delete ptr;              // must NOT leak (destructor virtual?)
// }

// #include "ScavTrap.hpp"

// int main()
// {
//     ScavTrap s("Tank");

//     for (int i = 0; i < 5; i++)
//         s.takeDamage(30);   // must die after HP = 0

//     s.guardGate();         // must not work if dead
// }
