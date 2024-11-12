/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/12 20:22:58 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "utils.h"

int main()
{
	std::cout << MAGENTA "[SPAN FULL TEST]" RESET << std::endl;
	try {
		Span sp;
		sp.addNumber(4);
		sp.addNumber(2);}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
	
	std::cout << MAGENTA "\n[SPAN TOO SMALL TEST]" RESET << std::endl;
	try {
		Span sp;
		sp.addNumber(4);
		std::cout << sp.shortestSpan() << std::endl;}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	std::cout << MAGENTA "\n[SUBJECT TEST]" RESET << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl; }
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

    return 0;
}
