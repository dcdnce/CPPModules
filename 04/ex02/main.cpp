/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:44:05 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 16:55:17 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define	N 2

int	main(void) {
	AAnimal	*a = new Cat();
	AAnimal	*b = new Dog();
	
	std::cout << std::endl;
	a->makeSound();
	b->makeSound();

	std::cout << std::endl;
	//AAnimal	*c = new AAnimal();

	delete a;
	delete b;
	return 0;
}
