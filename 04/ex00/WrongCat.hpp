/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:48:32 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 13:50:43 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		virtual ~WrongCat(void);

		void		makeSound(void);
};

#endif
