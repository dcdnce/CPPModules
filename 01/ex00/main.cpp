/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:33:15 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/13 08:18:49 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Zombie.h"

int	main(void) {
	Zombie z("Christophe"); 
	Zombie *zPtr = newZombie("Emmanuel");
	Zombie n;

	n.announce();
	z.announce();
	zPtr->announce();
	randomChump("Paul");

	delete zPtr;
	return (0);
}
