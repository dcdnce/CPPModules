/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:48:32 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:42:09 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog& src);
		virtual ~Dog(void);

		virtual void		makeSound(void); // Methode
};

#endif
