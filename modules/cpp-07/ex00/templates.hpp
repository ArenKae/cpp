/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:24:07 by acosi             #+#    #+#             */
/*   Updated: 2024/11/03 12:43:48 by acosi            ###   ########.fr       */
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



#endif