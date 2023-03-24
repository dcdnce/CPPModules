/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:28 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/11 14:10:26 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct  Data {
    uint8_t     x;
    uint32_t    y;
    uint64_t    z;
};

uintptr_t serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}

int main(void) {
    Data a = {1, 2, 3};
    
    std::cout << &a << std::endl;
    std::cout << deserialize(serialize(&a)) << std::endl;
}