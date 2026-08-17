#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    (void)cpy;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter(){}


bool    is_int(std::string literal)
{
    char *pos;
    long n = std::strtol(literal.c_str(), &pos, 10);
    (void)n;
    if (*pos == '\0')
        return true;
    return false;
}

bool    is_char(std::string literal)
{
    if (literal.size() == 1 && !std::isdigit(literal[0]))
        return true;
    return false;
}

bool    is_float(std::string literal)
{
    char *pos;
    float n = std::strtof(literal.c_str(), &pos);
    (void)n;
    if (*pos == 'f' && *(pos + 1) == '\0')
        return true;
    return false;
}

bool    is_double(std::string literal)
{
    char *pos;
    double n = std::strtod(literal.c_str(), &pos);
    (void)n;
    if (*pos == '\0')
        return (true);
    return false;
}

void ScalarConverter::printChar(double value, bool special)
{
    if (special || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else
    {
        int iv = static_cast<int>(value);
        if (std::isprint(iv))
            std::cout << "char: '" << static_cast<char>(iv) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(double value, bool special)
{
    if (special || value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool special)
{
    std::cout << "float: ";
    if (special)
    {
        std::cout << static_cast<float>(value) << "f" << std::endl;
        return;
    }
    if (value > FLT_MAX || value < -FLT_MAX)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(value);
    std::ostringstream oss;
    oss << f;
    std::string s = oss.str();
    if (s.find('.') == std::string::npos &&
        s.find('e') == std::string::npos)
        s += ".0";
    std::cout << s << "f" << std::endl;
}

void ScalarConverter::printDouble(double value, bool special)
{
    std::cout << "double: ";
    if (special)
    {
        std::cout << value << std::endl;
        return;
    }
    std::ostringstream oss;
    oss << value;
    std::string s = oss.str();
    if (s.find('.') == std::string::npos &&
        s.find('e') == std::string::npos)
        s += ".0";
    std::cout << value << std::endl;
}



void ScalarConverter::convert(const std::string &literal)
{
    double  value = 0;
    bool    special = false;

    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff" ||
        literal == "inf"  || literal == "inff")
    {
        special = true;
        value = std::strtod(literal.c_str(), NULL);
    }
    else if (is_char(literal))
        value = static_cast<double>(literal[0]);
    else if (is_int(literal))
        value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    else if (is_float(literal))
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (is_double(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value, special);
    printInt(value, special);
    printFloat(value, special);
    printDouble(value, special);
}