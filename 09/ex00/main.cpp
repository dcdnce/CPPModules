/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:00:13 by pforesti          #+#    #+#             */
/*   Updated: 2023/06/30 14:14:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

static inline int printError(std::string const str);
bool isValidDate(std::string const & str);
void outputDataByExchangeRate(BitcoinExchange & be, std::ifstream & ifs);

int main(int ac, char *av[]) {
    if (ac != 2)
        return (printError("could not open file"));

    BitcoinExchange be;
    be.setData("./data.csv");
    //std::cout << be << std::endl;

    std::ifstream ifs(av[1]);
    if (!ifs.is_open())
        return (printError("could not open file"));

    outputDataByExchangeRate(be, ifs);

    ifs.close();
    return (0);
}

void outputDataByExchangeRate(BitcoinExchange & be, std::ifstream & ifs) {
    std::string line, date, value;
    double  valueFloat;

    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::getline(ifs, line)) {
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            printError("bad input => " + line);
            continue ;
        }

        date = line.substr(0, pos);
        value = line.substr(pos + 1);
        valueFloat = std::stod(value);

        if (!isValidDate(date)) {
            printError("bad input => " + line);
            continue ;
        }

        if (valueFloat < 0.f) {
            printError("not a positive number.");
            continue ;
        }
        if (valueFloat > 1000.f) {
            printError("number too large.");
            continue;
        }

        std::cout << date << "=>" << value << " = " << \
            valueFloat * be.getValueByDate(date) << std::endl;
    }
}

bool isValidDate(const std::string& str) {
    if (str.length() != 11) 
        return (false);
    for (int i = 0; i < 4; ++i)
        if (!isdigit(str[i]))
            return (false);
    if (str[4] != '-' || str[7] != '-')
        return (false);
    if (!isdigit(str[5]) || !isdigit(str[6]))
        return (false);
    if (!isdigit(str[8]) || !isdigit(str[9]))
        return (false);

    return (true);
}

static inline int printError(std::string const str) {
    std::cerr << "Error: " << str << std::endl;
    return (1);
}