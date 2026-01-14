#ifndef BRAIN
# define BRAIN

#include <iostream>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& cpy);
        ~Brain();
        Brain &operator=(const Brain& cpy);
};

#endif 