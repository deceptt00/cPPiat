#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cerrno>
#include <iomanip>
#include <limits>

// ─── helpers ────────────────────────────────────────────────────────────────

static bool isSpecialFloat(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
	        s == "+inf" || s == "-inf" ||
	        s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string &s)
{
	// single printable character that is NOT a digit
	return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isInt(const std::string &s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[0] == '+' || s[0] == '-')
		++i;
	if (i == s.length())
		return false;
	for (; i < s.length(); ++i)
		if (!std::isdigit(s[i]))
			return false;
	return true;
}

static bool isFloat(const std::string &s)
{
	if (s.empty() || s[s.length() - 1] != 'f')
		return false;
	std::string trimmed = s.substr(0, s.length() - 1);
	if (trimmed.empty())
		return false;
	size_t i = 0;
	if (trimmed[0] == '+' || trimmed[0] == '-')
		++i;
	bool dot = false;
	for (; i < trimmed.length(); ++i) {
		if (trimmed[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(trimmed[i]))
			return false;
	}
	return dot; // must have a dot to distinguish from int + 'f'
}

static bool isDouble(const std::string &s)
{
	if (s.empty())
		return false;
	size_t i = 0;
	if (s[0] == '+' || s[0] == '-')
		++i;
	bool dot = false;
	for (; i < s.length(); ++i) {
		if (s[i] == '.') {
			if (dot) return false;
			dot = true;
		} else if (!std::isdigit(s[i]))
			return false;
	}
	return dot;
}

// ─── printers ───────────────────────────────────────────────────────────────

static void printChar(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
	float f = static_cast<float>(d);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" << std::endl;
	else {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}
}

static void printDouble(double d)
{
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+" : "-") << "inf" << std::endl;
	else {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << d << std::endl;
	}
}

static void printAll(double d)
{
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

// ─── convert ────────────────────────────────────────────────────────────────

void ScalarConverter::convert(const std::string &literal)
{
	// special pseudo-literals
	if (isSpecialFloat(literal)) {
		std::string base = literal;
		if (base[base.length() - 1] == 'f')
			base = base.substr(0, base.length() - 1);
		double d;
		if (base == "nan")  d = std::numeric_limits<double>::quiet_NaN();
		else if (base == "+inf") d = std::numeric_limits<double>::infinity();
		else                d = -std::numeric_limits<double>::infinity();
		printAll(d);
		return;
	}

	// char literal (single non-digit char)
	if (isCharLiteral(literal)) {
		double d = static_cast<double>(literal[0]);
		printAll(d);
		return;
	}

	// int
	if (isInt(literal)) {
		errno = 0;
		long l = std::strtol(literal.c_str(), NULL, 10);
		double d = static_cast<double>(l);
		printAll(d);
		return;
	}

	// float
	if (isFloat(literal)) {
		double d = static_cast<double>(std::strtof(literal.c_str(), NULL));
		printAll(d);
		return;
	}

	// double
	if (isDouble(literal)) {
		double d = std::strtod(literal.c_str(), NULL);
		printAll(d);
		return;
	}

	std::cout << "Error: unrecognized literal type." << std::endl;
}
