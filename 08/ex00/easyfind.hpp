/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:24:40 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/19 13:27:54 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T & container, int tofind) {
    return (std::find(container.begin(), container.end(), tofind));
}