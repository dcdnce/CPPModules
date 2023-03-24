/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:30:48 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/19 14:10:00 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>

#define FOUND(x) std::cout << x << " was found : true" << std::endl
#define NOT_FOUND(x) std::cout << x << " was found : false" << std::endl

int main(void) {
    std::vector<int> v;
    for (int i = 0 ; i < 10 ; i++)
        v.push_back(i+1);
    if (easyfind(v, 5) != v.end())
        FOUND(5);
    else 
        NOT_FOUND(5);
    if (easyfind(v, -1) != v.end())
        FOUND(-1);
    else
        NOT_FOUND(-1);

    std::array<int, 5> a = {-42, 58, -660, -12, 17};
    if (easyfind(a, 540) != a.end())
        FOUND(540);
    else
        NOT_FOUND(540);
    if (easyfind(a, -42) != a.end())
        FOUND(-42);
    else
        NOT_FOUND(-42);

    return (0);
}