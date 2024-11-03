/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:24:07 by acosi             #+#    #+#             */
/*   Updated: 2024/11/03 16:54:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename type, typename function>
void iter(type *array, size_t len, function F)
{
	for (size_t i = 0; i < len; ++i)
		F(array[i]);
};

/*   TEST FUNCTIONS   */

template<typename type>
void printElement(type &E)
{
	std::cout << E << " ";
};

template<typename type>
void incrementElement(type &E)
{
	++E;
};

template<typename type>
void to_42(type &E)
{
	E = 42;
};

#endif