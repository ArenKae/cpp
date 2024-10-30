/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:20 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 20:59:49 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "utils.h"
#include <iostream>
#include <cstdlib>	// For rand() and srand()
#include <ctime>	// For time()

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif