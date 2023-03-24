/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:43 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 14:15:36 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& src){
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat::~Cat(void) {
	std::cout << "Cat Default destructor called" << std::endl;
	delete this->_brain;
}

//#############################################################################################################################################
//#############################################################################################################################################

void		Cat::makeSound(void) {
	std::cout << "Miaou !" << std::endl;
}

//#############################################################################################################################################
//#############################################################################################################################################

Cat& Cat::operator=(const Cat& src) {
	this->type = src.type;
	this->_brain = src._brain;
	return (*this);
}
