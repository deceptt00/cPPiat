#pragma once

#include <map>
#include <iostream>
#include <iterator> 
#include <cstdlib>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> btcData;
    public:
        BitcoinExchange(std::string csv_data);
        BitcoinExchange(const BitcoinExchange &cpy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        float getValForDate(std::string &date);
        void    convertBitcoin(std::ifstream &input);
};