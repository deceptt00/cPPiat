#include "head.hpp"
#include <iostream>

bool		printable(std::string str)
{
		for (int i = 0; i <= str.size() - 1; i++)
		{
			if (std::isprint(str[i]) == 0)
				return false;
			if (str[i] == ' ')
				return false;
		}
		return true;
}


bool		is_num(std::string str)
{
		for (int i = 0; i <= str.size() - 1; i++)
		{
			if (std::isdigit(str[i]) == 0)
				return false;
		}
		return true;
}