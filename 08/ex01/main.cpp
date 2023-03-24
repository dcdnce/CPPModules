/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:28:12 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/20 15:07:05 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void) {
    // ADDNUMBER EXCEPTION
    {
        std::cout << "ADDNUMBER EXCEPTION" << std::endl;
        Span a(5);
        try {
            for (int i = 0 ; i < 6 ; i++)
                a.addNumber(i);
        } catch (std::exception &e) {std::cout << "exception caught: " << e.what() << std::endl;}
        a.print();
    }
    // SPAN EXCEPTION
    {
        std::cout << "SPAN EXCEPTION" << std::endl;
        Span b(1);
        b.addNumber(42);
        try {
            b.print();
        } catch (std::exception& e) {std::cout << "exception caught: " << e.what() << std::endl;}
    }
    std::cout << std::endl;
    // RANGE ITERATOR
    {
        std::cout << "RANGE ITERATOR" << std::endl;
        Span                c(10000);
        std::vector<int>    v;
        for (int i = 0 ; i < 10000 ; i++)
            v.push_back(i * 2);
        c.addNumber(v.begin(), v.end());
        c.print();
    }

    // RANGE ITERATOR EXCEPTION
    {
        std::cout << "RANGE ITERATOR EXCEPTION" << std::endl;
        Span d(5); 
        std::vector<int>    v;
        for (int i = 0 ; i < 10000 ; i++)
            v.push_back(i * 42);
        try {
            d.addNumber(v.begin(), v.end());
        } catch (std::exception& e) {std::cout << "exception caught: " << e.what() << std::endl;}
        d.print();

    }
    return (0);
}