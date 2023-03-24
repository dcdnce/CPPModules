/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:44:05 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/20 18:54:55 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void) {
	//ANIMAL CLASS
	Animal *a = new Animal();
	std::cout << "Animal a->type : " << a->getType() << std::endl;
	delete a;
	std::cout << std::endl;

	// DYNAMIC linking - virtual
	std::cout << "DYNAMIC LINKING" << std::endl;
	Animal *c = new Cat();
	Animal *d = new Dog();
	std::cout << "Cat c->type : " << c->getType() << std::endl;
	c->makeSound();
	std::cout << "Dog d->type : " << d->getType() << std::endl;
	d->makeSound();
	delete c;
	delete d;
	std::cout << std::endl;
	
	// STATIC linking
	std::cout << "STATIC LINKING" << std::endl;
	WrongAnimal *wc = new WrongCat();
	wc->makeSound();
	delete wc;
	std::cout << std::endl;

	return (0);
}
