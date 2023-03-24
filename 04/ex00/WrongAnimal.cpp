/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:55:10 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:32 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("_no_type") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = src;
}
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Default destructor called" << std::endl;
}

//#############################################################################################################################################
//#############################################################################################################################################

void		WrongAnimal::makeSound(void) {
	std::cout << "\"_no_sound\"" << std::endl;
}

std::string	WrongAnimal::getType(void) {
	return (this->type);
}

//#############################################################################################################################################
//#############################################################################################################################################


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	this->type = src.type;
	return (*this);
}
