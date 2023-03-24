/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:26 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/11 15:51:30 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"

Base *  generate(void) {
    int i = std::rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    return (new C);
}

void    identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "true type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "true type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "true type: C" << std::endl;
    else
        std::cout << "true type unknown" << std::endl;
}

void    identify(Base& p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "true type: A" << std::endl;
        return;
    } catch(std::bad_cast &bc) {}
    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "true type: B" << std::endl;
        return;
    } catch(std::bad_cast &bc) {}
    try {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << "true type: C" << std::endl;
        return;
    } catch(std::bad_cast &bc) {}
    std::cout << "true type unknown" << std::endl;
}

int main(void) {
    std::srand(std::time(nullptr));

    Base* p = generate();
    identify(p);
    identify(*p);
    return (0);
}