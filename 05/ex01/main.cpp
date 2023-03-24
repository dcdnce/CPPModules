/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:26 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/07 16:48:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Form	tooLow("", 151, 1);
	} 
	catch (std::exception& e) {std::cout << e.what();}
	try {
		Form	tooHigh("", 0, 1);
	}
	catch (std::exception& e) {std::cout << e.what();}

	Form	pis("Plan Implosion Syndicat", 3, 1);
	std::cout << pis << std::endl;

	Bureaucrat	emile("Emile de Girardin", 1);
	Bureaucrat	robert("Robert Lefebvre", 150);
	robert.signForm(pis);
	emile.signForm(pis);
	robert.signForm(pis);

	return (0);
}
