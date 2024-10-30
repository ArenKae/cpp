/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:26:54 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 16:02:10 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>		// For uintptr_t type
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
		
	private:
		// Default constructor #OrthodoxCanoncialForm
		Serializer(void);

		// Copy constructor #OrthodoxCanoncialForm
		Serializer(const Serializer &src);

		// Destructor #OrthodoxCanoncialForm
		~Serializer();

		// Assignment Operator #OrthodoxCanoncialForm
		Serializer& operator=(const Serializer &src);
};

#endif