/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:23 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/11 15:51:04 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
    public:
        virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};