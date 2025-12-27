
#ifndef CONTACT_H
#define CONTACT_H

#include "head.hpp"

class	Contact {
	public:
		Contact();
		~Contact();

		void	setName(std::string name);
		void	setLast(std::string last);
		void	setNick(std::string nick);
		void	setPhone(std::string phone);
		void	setSecret(std::string secret);
		std::string		getName() const;
		std::string		getLast() const;
		std::string		getNick() const;
		std::string		getPhone() const;
		std::string		getSecret() const;
		void	Summary() const;
		void 	Display() const;

	private:
		std::string	name;
		std::string	last;
		std::string	nick;
		std::string	phone;
		std::string	secret;
};

#endif