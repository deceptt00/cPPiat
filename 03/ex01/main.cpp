
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ClapTrap a;
    // ScavTrap b;

    std::cout << a.getEnergyPoints();
    return 0;
}

// int	main() {
// 	// ClapTrap	Clapy("Clapy");
// 	// ClapTrap	*Trapy = new ClapTrap("trappy");
// 	ScavTrap	Scavy("Scavy");

//     Scavy.setName("ali");
//     ScavTrap    trapy(Scavy);
//     trapy.setName("ho");
// 	// Clapy.attack("Scavy");
// 	// Scavy.takeDamage(Clapy.getAttackDamage());
// 	// Scavy.beRepaired(18);
// 	// Scavy.guardGate();
// 	// Scavy.attack("Trapy");
// 	// Trapy->takeDamage(Scavy.getAttackDamage());
// 	// delete Trapy;
// 	return 0;
// }


// int main()
// {
//     ScavTrap s("GateKeeper");

//     s.attack("enemy");
//     s.takeDamage(20);
//     s.beRepaired(10);
//     s.guardGate();
// }


// int main()
// {
//     ClapTrap *ptr = new ScavTrap("Polymorph");

//     ptr->attack("target");   // must call ClapTrap::attack unless virtual
//     delete ptr;              // must NOT leak (destructor virtual?)
// }


// int main()
// {
//     ScavTrap s("Tank");

//     for (int i = 0; i < 5; i++)
//         s.takeDamage(30);   // must die after HP = 0

//     s.guardGate();         // must not work if dead
// }
