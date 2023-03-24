/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:50:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:33:21 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal(void);
		Animal(const Animal & src);
		virtual ~Animal(void);	

		virtual void		makeSound(void); // Methode
		std::string			getType(void);

		Animal& operator=(const Animal& src);
};

#endif
