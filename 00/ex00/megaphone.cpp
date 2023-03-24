/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:15:40 by pforesti          #+#    #+#             */
/*   Updated: 2022/02/24 13:40:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1 ; i < ac ; i++)
		{
			std::string str(av[i]);
			for(size_t j = 0 ; j < str.size() ; j++)
				std::cout << (char)std::toupper(str[j]);
		}	
		std::cout << std::endl;	
	}
	return (0);
}
