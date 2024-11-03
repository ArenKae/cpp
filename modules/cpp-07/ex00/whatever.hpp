/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:24:07 by acosi             #+#    #+#             */
/*   Updated: 2024/11/03 16:06:00 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template<typename T>
void swap(T &x,T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
};

template<typename T>
const T &min(const T &x, const T &y)
{
	return (x < y ?  x : y);
};

template<typename T>
const T &max(const T &x, const T &y)
{
	return (x > y ? x : y);
};

#endif