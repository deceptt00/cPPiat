#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>   // uintptr_t (C++98 compatible via C header)

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data      *deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
};

#endif
