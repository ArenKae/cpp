/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:45:40 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 19:07:36 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCAT_HPP
#define WCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);
		WrongCat& operator=(const WrongCat &src);

		void makeSound(void) const;
};

#endif