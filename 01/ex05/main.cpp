/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:06:52 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/18 17:50:50 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Harl.h"

int	main(void) {
	Harl h;

	h.complain("DEBUG");
	std::cout << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	h.complain("ERROR");
}
