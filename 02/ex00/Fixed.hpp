
#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &other);
		~Fixed();

		Fixed&	operator=(Fixed const &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static const int	bits = 8;
};

#endif