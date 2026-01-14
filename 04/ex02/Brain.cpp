#include "Brain.hpp"

Brain::Brain()
{

}

Brain::Brain(const Brain& cpy)
{
    int i = 0;


	while (i < 100)
    {
        ideas[i] = cpy.ideas[i];
        i++;
    }
}

Brain::~Brain()
{

}


Brain &Brain::operator=(const Brain &cpy) {
	int i = 0;

	if (this != &cpy)
	{	
        while (i < 100)
        {
            ideas[i] = cpy.ideas[i];
            i++;
        }
    }
	return (*this);
}
