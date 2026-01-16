
#include "head.hpp"

PhoneBook::PhoneBook() : max_contacts(8), current_nb(0), nb_contacts(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact() 
{
	std::string	name;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	if (current_nb == 8)
		current_nb = 0;
	while (name.empty() || !printable(name))
	{

		std::cout << "Type name : ";
		std::getline(std::cin, name);
		if (std::cin.eof())
			return;
	}
	while (last.empty() || !printable(last))
	{
		std::cout << "Type surname : ";
		std::getline(std::cin, last);
		if (std::cin.eof())
			return;
	}
	while (nick.empty() || !printable(nick))
	{
		std::cout << "Type nickname : ";
		std::getline(std::cin, nick);
		if (std::cin.eof())
			return;
	}
	while (phone.empty() || !is_num(phone))
	{
		std::cout << "Type phone-number : ";
		std::getline(std::cin, phone);
		if (std::cin.eof())
			return;
	}
	while (secret.empty() || !printable(secret))
	{
		std::cout << "Type dark secret : ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			return;
	}
	array[current_nb].setLast(last);
	array[current_nb].setNick(nick);
	array[current_nb].setPhone(phone);
	array[current_nb].setName(name);
	array[current_nb].setSecret(secret);
	current_nb++;
	if (nb_contacts < 8)
		nb_contacts++;
}

void	PhoneBook::search_contact() {
	int	i = 0;
	std::string	ret;
	int	index;
	
	if (this->current_nb == 0) 
	{
		std::cout << "No contacts avalaible" << std::endl;
		sleep(1); 
		return;
	}
	std::cout << "+---------+----------+----------+---------+" << std::endl;
	std::cout << std::setw(10) << "Index " << "|";
	std::cout << std::setw(10) << "Firstname " << "|";
	std::cout << std::setw(10) << "Lastname " << "|";
	std::cout << std::setw(10) << "Nickname " << std::endl;
	std::cout << "+---------+----------+----------+---------+" << std::endl;
	while (i < nb_contacts) 
	{
		std::cout << std::setw(10) << i + 1 << "|";
		this->array[i].Summary();
		i++;
	}
	std::cout << std::endl << "Contact index : ";
	std::getline(std::cin, ret);
	index = atoi(ret.c_str());
	index--;
	if ((index == 0 && ret[0] != '1') || (index > 7 || index < 0) || (index >= this->nb_contacts)) 
	{
		std::cout << "Invalid index" << std::endl; 
		getchar();
		return;
	}
	array[index].Display();
	std::cout << "..." << std::endl;
	getchar();
}