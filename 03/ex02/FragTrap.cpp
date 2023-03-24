/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:31:50 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/17 13:53:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_name = "no_name";
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_name = name;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap& src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called" << std::endl;
}

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

void	FragTrap::highFiveGuys(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "Hello guys, my name is " << A_PINK << this->_name << A_ESC << ". Can i get some high fives ?" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		this->invalidAction();
}