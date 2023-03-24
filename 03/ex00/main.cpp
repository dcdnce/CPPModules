/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:56:21 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/18 10:52:57 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a; //Default 
	ClapTrap	b("Eric");//By name
	ClapTrap	c(b);//By copy
	ClapTrap	d("Roger");//By name 

	std::cout << std::endl;
	a.pokes();	
	b.pokes();	
	c.pokes();	
	d.pokes();	
	a = d;
	a.pokes();


	std::cout << std::endl;
	b.attack("a bad man");
	b.takeDamage(10);
	b.attack("a bad man");
	b.beRepaired(42);
	std::cout << "b hitPoints: " << b.getHitPoints() << std::endl;
	std::cout << "b energyPoints: " << b.getEnergyPoints() << std::endl;


	std::cout << std::endl;
	d.beRepaired(32);
	std::cout << "d hitPoints: " << d.getHitPoints() << std::endl;
	std::cout << "d energyPoints: " << d.getEnergyPoints() << std::endl;
	for (int i = 0 ; i < 11 ; i++)
		d.attack("nothing");

	std::cout << std::endl;
	return (0);
}
