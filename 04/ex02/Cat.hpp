/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:48:32 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 16:52:50 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain* _brain;

	public:
		Cat(void);
		Cat(const Cat& src);
		virtual ~Cat(void);

		virtual void		makeSound(void); // Methode

		Cat& operator=(const Cat& src);
};

#endif
