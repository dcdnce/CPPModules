/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:33:15 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 17:20:39 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Zombie.h"

int	main(void) {
	int	n = 5;

	Zombie	*a = zombieHorde(n, "Horde");

	for (int i = 0 ; i < n ; i++)
		a[i].announce();

	delete [] a;
	return (0);
}
