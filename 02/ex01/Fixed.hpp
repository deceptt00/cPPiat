
#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &other);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed&	operator=(Fixed const &other);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& o, Fixed const &other);

#endif