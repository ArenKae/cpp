/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:26:23 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 16:03:41 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*	A reinterpret_cast can convert any memory data to any type.
	There are no protections against bad usage, so it must be used carefully.

	uintptr_t : An unsigned integer type with the property that any valid pointer to void 
	can be converted to this type, then converted back to pointer to void, and the result 
	will compare equal to the original pointer. */

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}