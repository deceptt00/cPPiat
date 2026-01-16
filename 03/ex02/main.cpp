
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap	Calpy("Calpy");
	ClapTrap	*trapy = new ClapTrap("trapy");
	ScavTrap	Scavy("Scavy");
	FragTrap	Fragy("Fragy");

	Calpy.attack("Scavy");
	Scavy.takeDamage(Calpy.getAttackDamage());
	Scavy.beRepaired(18);
	Scavy.guardGate();
	Scavy.attack("trapy");
	trapy->takeDamage(Scavy.getAttackDamage());
	delete trapy;
	Fragy.attack("Scavy");
	Scavy.takeDamage(Fragy.getAttackDamage());
	Fragy.highFivesGuys();
	return 0;
}



// int main()
// {
//     FragTrap f("Battery");

//     for (int i = 0; i < 110; i++)
//         f.attack("air");

//     f.highFivesGuys(); // must NOT work if energy = 0
// }


// int main()
// {
//     ClapTrap *ptr = new FragTrap("Poly");

//     ptr->attack("target");
//     delete ptr;   // destructor must be correct
// }
