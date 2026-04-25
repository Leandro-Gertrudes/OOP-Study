/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:46:15 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 16:56:35 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP

#define EASYFIND_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfinder(T &container, int target){
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if(it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

#endif