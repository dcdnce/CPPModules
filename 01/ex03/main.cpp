/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:32:07 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 19:50:08 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"
#include <iostream>

int	main(void) {
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();	
	}
	std::cout << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB 	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
