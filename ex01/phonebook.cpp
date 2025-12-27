
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

	if (this->current_nb == 8)
		this->current_nb = 0;
	while (name.empty())
	{
		std::cout << "Type name : ";
		std::getline(std::cin, name);
	}
	while (last.empty())
	{
		std::cout << "Type surname : ";
		std::getline(std::cin, last);
	}
	while (nick.empty())
	{
		std::cout << "Type nickname : ";
		std::getline(std::cin, nick);
	}
	while (phone.empty())
	{
		std::cout << "Type phone-number : ";
		std::getline(std::cin, phone);
	}
	while (secret.empty())
	{
		std::cout << "Type dark secret : ";
		std::getline(std::cin, secret);
	}
	this->array[this->current_nb].setLast(last);
	this->array[this->current_nb].setNick(nick);
	this->array[this->current_nb].setPhone(phone);
	this->array[this->current_nb].setName(name);
	this->array[this->current_nb].setSecret(secret);
	this->current_nb++;
	if (nb_contacts < 8)
		nb_contacts++;
}

void	PhoneBook::search_contact() {
	int	i = 0;
	std::string	ret;
	int	index;
	
	if (this->current_nb == 0) 
	{
		std::cout << "No contact avalaible" << std::endl;
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
		std::cout << std::setw(10) << i << "|";
		this->array[i].Summary();
		i++;
	}
	std::cout << std::endl << "Contact index : ";
	std::getline(std::cin, ret);
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0') || (index > 7 || index < 0) || (index >= this->nb_contacts)) 
	{
		std::cout << "Invalid index" << std::endl; 
		getchar();
		return;
	}
	this->array[index].Display();
	std::cout << "..." << std::endl;
	getchar();
}