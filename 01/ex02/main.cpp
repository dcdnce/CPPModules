/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:21:59 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/16 17:37:02 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "String Addr: " << &string << std::endl;
	std::cout << "StringPTR held Addr: " << stringPTR << std::endl;
	std::cout << "StringREF held Addr: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String : " << string << std::endl;
	std::cout << "StringPTR held value: " << *stringPTR << std::endl;
	std::cout << "StringREF held value: " << stringREF << std::endl;
	return (0);
}
