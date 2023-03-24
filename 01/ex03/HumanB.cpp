/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:01:41 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/17 14:22:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.h"
#include "HumanB.h"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
