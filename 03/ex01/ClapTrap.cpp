/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:13:36 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/17 13:13:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("no_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

void	ClapTrap::invalidAction(void) {
	std::cout << A_PINK << "ClapTrap " << this->_name << " can't do this." << A_ESC << std::endl;
}

void	ClapTrap::pokes(void) {
	std::cout << "Booting sequence complete. Hello! I am your new steward bot. Designation: CL4P-TP, Hyperion Robot, Class C, named " << A_PINK << this->_name << A_ESC << ". Please adjust factory settings to meet your needs before deployment." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks "<< target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		this->invalidAction();
}

void	ClapTrap::takeDamage(unsigned  int amount) {
	if (this->_hitPoints > 0) {
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0) this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;
	}
	else
		this->invalidAction();
}

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

int	ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }

int	ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }

int	ClapTrap::getAttackDamage(void) const {	return (this->_attackDamage); }

std::string	ClapTrap::getName(void) const {	return (this->_name); }

/*********/ /*********/ /*********/
/*********/ /*********/ /*********/

ClapTrap & ClapTrap::operator=(const ClapTrap& src) {
	this->_name = src.getName();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	this->_hitPoints = src.getHitPoints();
	return (*this);
}
