#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(std::string csv_data)
{
    std::ifstream input(csv_data.c_str());
    std::string line;

    if (!input.is_open())
        throw std::runtime_error("Could not open input");
    std::getline(input, line);
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string key;
        std::string val;
        std::getline(ss, key, ',');
        std::getline(ss, val);
        btcData.insert(std::make_pair(key, std::strtof(val.c_str(), NULL)));
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    btcData = cpy.btcData;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        btcData = other.btcData;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void isValidDate(const std::string &dateStr) {
    if (dateStr.find(" ") != std::string::npos)
        throw std::runtime_error("bad input => " + dateStr);
    std::stringstream ss(dateStr);
    std::string year, month, day;
    long y, m, d;
    
    if (!std::getline(ss, year, '-') ||
        !std::getline(ss, month, '-') ||
        !std::getline(ss, day) ||
        year.size() != 4 || month.size() != 2 || day.size() != 2)
        throw std::runtime_error("bad input => " + dateStr);
    y = std::strtol(year.c_str(), NULL, 10);
    m = std::strtol(month.c_str(), NULL, 10);
    d = std::strtol(day.c_str(), NULL, 10);
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        days_in_month[1] = 29;
    if (y < 2000 || m < 1 || m > 12 || d < 1 || d > days_in_month[m - 1])
        throw std::runtime_error("bad input => " + dateStr);
}

float   BitcoinExchange::getValForDate(std::string &date)
{
    std::map<std::string, float>::iterator it;

    it = btcData.upper_bound( date);
    if (it == btcData.begin())
        throw std::runtime_error("bad input => " + date);
    it--;
    return it->second;
}

float   isValidBtc(const std::string &val)
{
    if (val.empty())
        throw std::runtime_error("bad input =>");
    if (val.find(" ") != std::string::npos)
        throw std::runtime_error("bad input =>" + val);
    char* end;
    float btcAmount = std::strtof(val.c_str(), &end);
    if (*end != '\0')
        throw std::runtime_error("bad input =>" + val);;    
    if (btcAmount < 0 )
        throw std::runtime_error("not a positive number." + val);
    else if (btcAmount > 1000)
        throw std::runtime_error("too large a number." + val);
    return btcAmount;
}

void    BitcoinExchange::convertBitcoin(std::ifstream &input)
{
    std::string line;
    std::string date;
    std::string strAmount;
    size_t      sep;
    float       btc;
    float       btcAmount;

    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid input");
    while (std::getline(input, line))
    {
        try
        {
            sep = line.find(" | ");
            if (sep == std::string::npos)
                throw std::runtime_error("bad input => " + line);
            date = line.substr(0, sep);
            strAmount = line.substr(sep + 3);
            isValidDate(date);
            btcAmount = isValidBtc(strAmount);
            btc = getValForDate(date);
            std::cout << date << " => " << strAmount << " = " << btc * btcAmount << std::endl;
        }
        catch (std::exception &e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}