/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:50:33 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 18:07:47 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(void) { 
}

Weapon::Weapon(std::string type) : _type(type) { 
}

Weapon::~Weapon(void) {
}

const std::string& Weapon::getType(void) {
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}
