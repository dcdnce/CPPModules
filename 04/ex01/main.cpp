/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:44:05 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/03 16:06:31 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define	N 2

int	main(void) {
	Animal	*t[N]; // tab of 4 Animal ptr

	for (int i = 0 ; i < N ; i++)
		i % 2 ? t[i] = new Cat() : t[i] = new Dog();

	std::cout << std::endl;	

	//	Cat & Dog destructors are called meaning _brains objects are freed.
	for (int i = 0 ; i < N ; i++)
		delete t[i];

	return 0;
}
