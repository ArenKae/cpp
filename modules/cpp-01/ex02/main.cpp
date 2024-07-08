/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:07:36 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:27:15 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string     string = "HI THIS IS BRAIN";
	std::string*    stringPTR = &string;
	std::string&    stringREF = string;

	std::cout << "The adress of string is " << &string << std::endl;
	std::cout << "The adress of stringPTR is " << stringPTR << std::endl;
	std::cout << "The adress of stringREF is " << &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "The value of string is " << string << std::endl;
	std::cout << "The value of stringPTR is " << *stringPTR << std::endl;
	std::cout << "The value of string is " << stringREF << std::endl;
	
	return 0;
}