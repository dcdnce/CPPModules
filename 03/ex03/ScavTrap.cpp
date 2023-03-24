/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:57:10 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 13:36:08 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_name = "no_name";
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->_name = name;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap& src) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

void	ScavTrap::guardGate(void) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "Scavtrap " << this->_name << " has entered Gate Keeper mode." << std::endl;
		this->_energyPoints -= 1;
	}
	else
		this->invalidAction();
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap type ScavTrap " << this->_name << " attacks "<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		this->invalidAction();
}

