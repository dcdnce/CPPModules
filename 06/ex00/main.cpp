/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:59:15 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/11 13:44:36 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include <limits>

template<typename T>
bool inLimits(double n) {
    if (std::numeric_limits<T>::is_integer)
        return (n <= std::numeric_limits<T>::max() && n >= std::numeric_limits<T>::min());
    return (n <= std::numeric_limits<T>::max() && n >= -std::numeric_limits<T>::max());
}

void convertChar(double n) {
    std:: cout << "char: ";
    if (!inLimits<char>(n)) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(n)) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;;
    }
}

void convertInt(double n) {
    std:: cout << "int: ";
    if (!inLimits<int>(n)) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<int>(n) << std::endl;;
    }
}

void convertFloat(double n) {
    std::string s = std::to_string(n);
    
    std::cout << "float: ";
    if (s == "nan" || s == "inf" || s == "-inf") {
        std::cout << s << "f" << std::endl;
    }
    else if (!inLimits<float>(n)) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<float>(n);
        if (n == roundf(n))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void convertDouble(double n) {
    std::string s = std::to_string(n);
    
    std::cout << "double: ";
    if (s == "nan" || s == "inf" || s == "-inf") {
        std::cout << s << std::endl;
    }
    else if (!inLimits<double>(n)) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<double>(n);
        if (n == roundf(n))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

int main(int ac, char **av) {
    double  n;

    if (ac != 2)
        return (0);
     
    try {
        n = std::stod(av[1]);
    } catch (std::invalid_argument & ia) {
        if (std::strlen(av[1]) != 1)
            return (0);
        n = std::stod(std::to_string((int)av[1][0]));
    } 

    convertChar(n);
    convertInt(n);
    convertFloat(n);
    convertDouble(n);

    return (0);
}