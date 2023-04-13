/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:00:07 by pforesti          #+#    #+#             */
/*   Updated: 2023/04/12 11:02:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

static inline int printError(void);

int main(int ac, char *av[]) {
    RPN rpn; 
    if (ac != 2)
        return (printError());

    try {
        rpn.setExpression(av[1]);
        rpn.compute();
        std::cout << rpn.getResult() << std::endl;
    } catch (std::exception & e) {printError();}

    return (0);
}

static inline int printError(void) {
    std::cerr << "Error" << std::endl;
    return (1);
}