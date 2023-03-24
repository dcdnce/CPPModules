/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:06:52 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/18 17:58:57 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Harl.h"

int	main(int ac, char **av) {
	Harl		h;
	std::string	level = "";

	if (ac > 1)
		level = av[1];
	h.complain(level);
}
