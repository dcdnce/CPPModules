/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:59:48 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/17 14:05:25 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.h"

class HumanA {
	private:
		std::string _name;
		Weapon& 	_weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);	
		void		attack(void);
};

#endif
