/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:56:21 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/18 11:30:40 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap a;
	ScavTrap b("Gerard");
	ScavTrap c(b);

	std::cout << std::endl;
	a = b;
	a.pokes();
	b.pokes();
	c.pokes();

	std::cout << std::endl;
	std::cout << a.getName() << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;

	std::cout << std::endl;
	a.guardGate();
	a.attack("a lost ClapTrap");
	a.takeDamage(99);

	std::cout << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;


	std::cout << std::endl;
	return (0);
}
