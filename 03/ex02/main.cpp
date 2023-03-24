/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:56:21 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/17 14:31:43 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap a;
	FragTrap b("Raymond");
	FragTrap c(b);

	std::cout << std::endl;
	a.pokes();
	a = b;
	b.pokes();
	c.pokes();

	std::cout << std::endl;
	std::cout << a.getName() << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;

	std::cout << std::endl;
	a.highFiveGuys();
	a.attack("a lost ScavTrap");
	a.takeDamage(99);

	std::cout << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;


	std::cout << std::endl;
	return (0);
}
