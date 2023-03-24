/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:45:24 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 18:36:34 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void);
		void				setType(std::string type);
};

#endif
