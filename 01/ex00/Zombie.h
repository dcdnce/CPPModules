/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:33:24 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/13 08:10:51 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

class	Zombie {
	private:
		std::string	_name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif
