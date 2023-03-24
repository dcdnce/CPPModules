/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:55:10 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:30:42 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("_no_type") {
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = src;
}
AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Default destructor called" << std::endl;
}

//#############################################################################################################################################
//#############################################################################################################################################

std::string	AAnimal::getType(void) {
	return (this->type);
}

//#############################################################################################################################################
//#############################################################################################################################################


AAnimal& AAnimal::operator=(const AAnimal& src) {
	this->type = src.type;
	return (*this);
}
