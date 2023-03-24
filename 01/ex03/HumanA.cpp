/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:01:41 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/17 14:05:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.h"
#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
