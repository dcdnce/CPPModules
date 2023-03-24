/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:50:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 16:45:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal(void);
		AAnimal(const AAnimal & src);
		virtual ~AAnimal(void);	

		virtual void		makeSound(void) = 0; // Methode pure
		std::string			getType(void);

		AAnimal& operator=(const AAnimal& src);
};

#endif
