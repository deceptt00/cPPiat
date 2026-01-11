
#include "ClapTrap.hpp"

// int	main() {
// 	ClapTrap	Clapy("Clapy");
// 	ClapTrap	Trapy("Trapy");

// 	Clapy.attack("Roméo");
// 	Trapy.takeDamage(Clapy.getAttackDamage());
// 	Trapy.beRepaired(2);

// 	return 0;
// }

// #include "ClapTrap.hpp"

// int main()
// {
//     ClapTrap a("Ali");
//     ClapTrap b("Bot");

//     a.attack("Bot");
//     b.takeDamage(0);
//     b.attack("Ali");
//     a.takeDamage(5);
//     a.beRepaired(3);
// }

// #include "ClapTrap.hpp"

// int main()
// {
//     ClapTrap c("NoEnergy");

//     for (int i = 0; i < 15; i++)
//         c.attack("wall");

//     c.beRepaired(10); // should NOT work after energy = 0
// }

// #include "ClapTrap.hpp"

int main()
{
    ClapTrap d("Dead");

    d.takeDamage(5);
    d.takeDamage(10); // should die
    d.attack("someone"); // must NOT attack
    d.beRepaired(10); // must NOT repair
}
