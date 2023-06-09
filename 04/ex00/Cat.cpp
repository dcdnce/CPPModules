/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:43 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:22:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& src){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout << "Cat Default destructor called" << std::endl;
}
//
//#############################################################################################################################################
//#############################################################################################################################################

void		Cat::makeSound(void) {
	std::cout << "Miaou !" << std::endl;
}
