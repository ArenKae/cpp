/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:41:25 by acosi             #+#    #+#             */
/*   Updated: 2024/11/25 08:41:23 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>		// string stream manipulation
#include <stdexcept>

class RPN
{
	public:
		// Orthodox Canoncial Form
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN& operator=(const RPN &src);

		// Main member function
		int compute(const std::string &arg);

	private:
		// Helper member functions
		bool performOperation(int a, int b, char op) const;
		bool isNumber(const std::string &token);
		bool isOperator(const std::string &token);	
};

#endif