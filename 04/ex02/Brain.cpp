/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:58:47 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 14:04:25 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain & src) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor Called" << std::endl;
}

//#############################################################################################################################################
//#############################################################################################################################################

Brain&	Brain::operator=(const Brain & src) {
	for (int i = 0 ; i < 100 ; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}
