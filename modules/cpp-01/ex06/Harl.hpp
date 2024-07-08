/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:56:14 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 05:23:26 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl(void);
	~Harl(void);
    void complain(std::string level);
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif