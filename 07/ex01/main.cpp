/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:32:00 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 12:58:39 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void increment(T & a) {
    a += 1;
}

int main(void) {
    int it[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char ct[10] = "aaaaaaaaa";
    
    for (int i = 0 ; i < 10 ; i++)
        std::cout << it[i]; 
    std::cout << std::endl;
    std::cout << ct << std::endl;

    iter<int, void(*)(int&)>(it, 10, increment);
    iter<char, void(*)(char&)>(ct, 9, increment);

    for (int i = 0 ; i < 10 ; i++)
        std::cout << it[i];
    std::cout << std::endl;
    std::cout << ct << std::endl;
    
    return (0);
}