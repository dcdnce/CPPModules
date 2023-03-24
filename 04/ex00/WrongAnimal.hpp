/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:50:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 13:50:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & src);
		virtual ~WrongAnimal(void);	

		void				makeSound(void);
		std::string			getType(void);

		WrongAnimal& operator=(const WrongAnimal& src);
};

#endif
