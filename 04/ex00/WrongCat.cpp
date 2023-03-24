/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:43 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:03 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src){
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Default destructor called" << std::endl;
}
//
//#############################################################################################################################################
//#############################################################################################################################################

void		WrongCat::makeSound(void) {
	std::cout << "Miaou !" << std::endl;
}
