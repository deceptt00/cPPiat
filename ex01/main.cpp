#include "head.hpp"
#include "phonebook.hpp"

int main() {
    PhoneBook phonebook;
    std::string cmd;

    while (true) {
		system("clear");
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, cmd))
		{
			system("clear");
            break;
		}
        if (cmd == "ADD")
            phonebook.add_contact();
        else if (cmd == "SEARCH")
            phonebook.search_contact();
        else if (cmd == "EXIT")
        {
			system("clear");
            break;
		}
    }
    return 0;
}