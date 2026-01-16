
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>


class Harl {
	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

#endif