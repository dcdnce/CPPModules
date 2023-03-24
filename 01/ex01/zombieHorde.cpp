/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:20:30 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 17:20:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie *a = new Zombie[N];

	for (int i = 0 ; i < N ; i++)
		a[i].setName(name);
	return (a);
}
