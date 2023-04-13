/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:32:16 by pforesti          #+#    #+#             */
/*   Updated: 2023/04/11 16:2 09:19:25 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {*this = src;}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setData(std::string const filePath) {
    std::ifstream   ifs(filePath);
    std::string date, exchange_rate;

    if (!ifs.is_open())
        throw std::runtime_error("could not open 1st database file");

    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (std::getline(ifs, date, ',') && std::getline(ifs, exchange_rate, '\n'))
        this->_data[date] = std::stod(exchange_rate);
    
    ifs.close();
}

std::map<std::string, double>   BitcoinExchange::getData() const {
    return (_data);
}

double BitcoinExchange::getValueByDate(std::string const date) {
    std::map<std::string, double>::iterator it;
    
    it = _data.lower_bound(date);
    if (it->first != date)
        if (it != _data.begin())
            it = --it;
            
    return (it->second);
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    this->_data = rhs.getData();
    return (*this);
}

std::ostream& operator<<(std::ostream & os, BitcoinExchange const & be) {
    std::map<std::string, double> data = be.getData();

    for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
            os << it->first << ": " << it->second << std::endl;
    return (os);
}