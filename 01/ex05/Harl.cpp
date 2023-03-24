/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:30:35 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/18 17:47:27 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>

Harl::Harl(void) {
	this->_indices[0] = "DEBUG";	
	this->_foo[0] = &Harl::_debug;
	this->_indices[1] = "INFO";	
	this->_foo[1] = &Harl::_info;
	this->_indices[2] = "WARNING";	
	this->_foo[2] = &Harl::_warning;
	this->_indices[3] = "ERROR";	
	this->_foo[3] = &Harl::_error;
}

Harl::~Harl(void) {
}

void	Harl::complain(std::string level) {
	for (int i = 0 ; i < 4 ; i++)
		if (this->_indices[i] == level)
			(void)(this->*_foo[i])();
}

void	Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

