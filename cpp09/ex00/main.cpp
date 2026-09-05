#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    try
    {
        std::ifstream file(av[1]);
        if (!file.is_open())
            throw std::runtime_error("could not open file");
        
        BitcoinExchange btc("data.csv");
        btc.convertBitcoin(file);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}