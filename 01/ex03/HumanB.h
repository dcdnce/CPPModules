/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:59:48 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/17 14:20:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.h"

class HumanB {
	private:
		std::string _name;
		Weapon* 	_weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);	
		void		attack(void);
		void		setWeapon(Weapon& weapon);
};

#endif
