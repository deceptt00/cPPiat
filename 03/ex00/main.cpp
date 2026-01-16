
#include "ClapTrap.hpp"

// int	main() {
// 	ClapTrap	Clapy("Clapy");
// 	ClapTrap	Trapy("Trapy");

// 	Clapy.attack("ali");
// 	Trapy.takeDamage(Clapy.getAttackDamage());
// 	Trapy.beRepaired(2);

// 	return 0;
// }


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


// int main()
// {
//     ClapTrap c("Clapy");

//     c.setAttackDamage(5);
//     for (int i = 0; i < 15; i++)
//         c.attack("wall");

//     c.beRepaired(10);
// }


int main()
{
    ClapTrap d("clapy");

    d.takeDamage(5);
    d.takeDamage(10); 
    d.attack("someone");
    d.beRepaired(10); 
}
