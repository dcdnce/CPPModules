/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:33:29 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 17:18:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Zombie.h"

Zombie::Zombie(void) : _name("zombie_undefined"){
}

Zombie::Zombie(std::string s) : _name(s) {
}

Zombie::~Zombie(void) {
	std::cout << "Zombie instance named " + this->_name +  " destroyed." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}
void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
