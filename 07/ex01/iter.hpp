/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:35:38 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 12:36:31 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename F>
void iter(T* t, uint8_t size, F f) {
    if (!t || !size)
        return ;
    for (int i = 0 ; i < size ; i++)
        f(t[i]);
}