/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:53:51 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 13:59:23 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
	public:
		Brain(void);
		Brain(const Brain & src);
		~Brain(void);

		std::string	ideas[100];

		Brain& operator=(const Brain & src);
};



#endif