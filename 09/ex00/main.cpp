#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

static inline int printError(std::string str) {
    std::cerr << "Error: " << str << std::endl;
    return (1);
}

int main(int ac, char *av[]) {
    if (ac != 2)
        return (printError("could not open 2nd database file"));

    BitcoinExchange be;
    be.setData("./data.csv");
    //std::cout << be << std::endl;

    std::string date, value;
    std::ifstream ifs(av[1]);

    if (!ifs.is_open())
        return (printError("could not open file"));

    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::getline(ifs, date, '|') && std::getline(ifs, value, '\n')) {
        be.getValueByDate(date);
    }

    return (0);
}