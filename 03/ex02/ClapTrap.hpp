/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 09:07:47 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/18 11:14:26 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define	A_PINK	"\e[38;5;225m"
#define	A_ESC	"\e[0m"

#include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src); 
		~ClapTrap(void);

		std::string	getName(void) const;
		int	getHitPoints(void) const;
		int	getEnergyPoints(void) const;
		int	getAttackDamage(void) const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	invalidAction(void);
		void	pokes(void);

		ClapTrap& operator=(const ClapTrap& src);
};

#endif
