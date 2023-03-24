/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:51 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 12:30:47 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T & min(T & a, T & b) {
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T & max(T & a, T & b) {
    if (a > b)
        return (a);
    return (b);
}