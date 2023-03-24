/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:48:32 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 14:10:43 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(const Dog& src);
		virtual ~Dog(void);

		virtual void		makeSound(void); // Methode

		Dog& operator=(const Dog& src);
};

#endif
