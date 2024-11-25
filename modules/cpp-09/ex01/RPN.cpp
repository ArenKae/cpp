/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:41:30 by acosi             #+#    #+#             */
/*   Updated: 2024/11/25 09:12:39 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

RPN::RPN() {};
	
RPN::RPN(const RPN &src) {(void)src;};

RPN::~RPN() {};

RPN& RPN::operator=(const RPN &src)
{
	(void)src;
	return *this;
}

/**********************************/
/*******[ MEMBER FUNCTIONS ]*******/
/**********************************/

int RPN::compute(const std::string &arg)
{
	// Create a stack to store the operands
	std::stack<int> stack;

	// Create an input string stream object from the string arg
	std::istringstream iss(arg);

	// Create a string to hold the current token
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
			stack.push(std::atoi(token.c_str()));
		else if (isOperator(token))
	}
	
}

// Check if the current token is a single digit between 0 and 9
bool RPN::isNumber(const std::string &token)
{
	return token.size() == 1 && std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token)
{
	return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}