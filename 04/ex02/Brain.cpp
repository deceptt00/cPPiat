#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain has be constructed" << std::endl;
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
    std::cout << "Brain has been destroyed" << std::endl;

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

void Brain::setbrainidea(const std::string str) {
	int i = 0;

    while (i < 100)
    {
        ideas[i] = str;
        i++;
    }
}

void Brain::getbrainidea() {
	int i = 0;

    while (i < 100)
    {
        std::cout << ideas[i] << std::endl;
        i++;
    }
}
