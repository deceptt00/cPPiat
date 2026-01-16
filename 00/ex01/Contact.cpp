
#include "head.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setName(std::string name) {
	this->name = name;
}

void	Contact::setLast(std::string last) {
	this->last = last;
}

void	Contact::setNick(std::string nick) {
	this->nick = nick;
}

void	Contact::setPhone(std::string phone) {
	this->phone = phone;
}

void	Contact::setSecret(std::string secret) {
	this->secret = secret;
}

std::string 	Contact::getName() const {
	return this->name;
}

std::string Contact::getLast() const {
	return this->last;
}

std::string Contact::getNick() const {
	return this->nick;
}

std::string Contact::getPhone() const {
	return this->phone;
}

std::string	Contact::getSecret() const {
	return this->secret;
}


void Contact::Summary() const {
	std::string	name;
	std::string	last;
	std::string	nick; 
	
	name = this->getName();
	last = this->getLast();
	nick = this->getNick();
	if (name.length() > 9)
		name = name.substr(0, 9) + ".";
	if (last.length() > 9)
		last = last.substr(0, 9) + ".";
	if (nick.length() > 9)
		nick = nick.substr(0, 9) + ".";
	std::cout << std::setw(10) << name << "|";
	std::cout << std::setw(10) << last << "|";
	std::cout << std::setw(10) << nick << std::endl;	

}

void Contact::Display() const {
	
	std::cout << "Name : " << this->getName() << std::endl;
	std::cout << "Lastname : " << this->getLast() << std::endl;
	std::cout << "Nickname : " << this->getNick() << std::endl;
	std::cout << "Phone number : " << this->getPhone() << std::endl;
	std::cout << "Darkest secret : " << this->getSecret() << std::endl;
	std::cout << std::endl;	
}	
