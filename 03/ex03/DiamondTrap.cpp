/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:34 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/17 15:39:06 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = "no_name";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	this->_energyPoints = this->ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	this->_energyPoints = this->ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is " << A_PINK << _name << A_ESC << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}