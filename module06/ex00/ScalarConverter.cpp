/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:00:50 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/21 15:30:01 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& s)
{
    return (s.length() == 1 && !isdigit(s[0]));
}

static bool isInt(const std::string& s)
{
    char* end;
    long result = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    return (result >= std::numeric_limits<int>::min()
            && result <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;
    char* end;
    std::strtof(s.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& s)
{
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;
    char* end;
    std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal)
{
    double value;

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        value = static_cast<double>(std::atof(literal.c_str()));
    else if (isDouble(literal))
        value = std::atof(literal.c_str());
    else
    {
        std::cout << "Invalid input\n";
        return;
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!isprint(static_cast<int>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    // INT
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)
        || value > std::numeric_limits<int>::max()
        || value < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    // FLOAT
    std::cout.unsetf(std::ios::fixed);
    std::cout << "float: " << std::setprecision(6)
            << static_cast<float>(value) << "f\n";

    // DOUBLE
    std::cout.unsetf(std::ios::fixed);
    std::cout << "double: " << std::setprecision(6)
              << static_cast<double>(value) << "\n";
}