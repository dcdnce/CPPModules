/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:29:54 by pforesti          #+#    #+#             */
/*   Updated: 2023/04/11 16:19:20 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <fstream>
#include <string>
#include <iostream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
    public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & src);
    ~BitcoinExchange();
    

    
    void    setData(std::string const filePath);
    std::map<std::string, double>   getData() const;
    int  getValueByDate(std::string const date);
    
    BitcoinExchange & operator=(BitcoinExchange const & rhs);
};

std::ostream& operator<<(std::ostream & os, BitcoinExchange const & be);