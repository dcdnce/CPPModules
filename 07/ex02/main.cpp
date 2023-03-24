/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:20:00 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 15:09:52 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    Array<int> a;
    std::cout << "Array<int> a;" << std::endl;
    std::cout << "a: " << a << std::endl;
    try {
        std::cout << "a[0]: " << a[0] << std::endl; 
    } catch(std::exception &e) {std::cout << e.what() << std::endl;}
    try {
        std::cout << "a[-1]: " << a[-1] << std::endl; 
    } catch(std::exception &e) {std::cout << e.what() << std::endl << std::endl;}

    
    Array<int> b(5);
    for (size_t i = 0 ; i < 5 ; i++)
        b[i] = i + 1;
    std::cout << "Array<int> b(5);" << std::endl;
    std::cout << "for (size_t i = 0 ; i < 5 ; i++)\n\tb[i] = i + 1;" << std::endl;
    std::cout << "b: " << b << std::endl << std::endl;
    
    Array<int> c(b);
    std::cout << "Array<int> c(b);" << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "for (size_t i = 0 ; i < 5 ; i++)\n\tb[i]++;" << std::endl;
    for (size_t i = 0 ; i < 5 ; i++)
        b[i]++;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl << std::endl;
}