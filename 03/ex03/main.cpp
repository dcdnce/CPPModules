/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:56:21 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 17:22:28 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap a("Raymond");

	a.pokes();
	a.whoAmI();

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << a.getHitPoints() << std::endl;
	std::cout << a.getEnergyPoints() << std::endl;
	std::cout << a.getAttackDamage() << std::endl;
	a.highFiveGuys();
	a.attack("a lost ClapTrap");

	std::cout << std::endl;
	return (0);
}
