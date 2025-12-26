
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Harl {
	public:
		Harl();
		~Harl();

		void	complain(str level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

#endif