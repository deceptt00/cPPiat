#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(ScalarConverter &other);
        ~ScalarConverter();

        static void printChar(double value, bool special);
        static void printInt(double value, bool special);
        static void printFloat(double value, bool special);
        static void printDouble(double value, bool special);

    public:
        static void convert(const std::string &literal);
};

bool    is_int(std::string literal);
bool    is_char(std::string literal);
bool    is_float(std::string literal);
bool    is_double(std::string literal);

#endif