/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/12 21:09:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "utils.h"

int main()
{
	// Test when the span is full and another element is added
	std::cout << MAGENTA "[SPAN FULL TEST]" RESET << std::endl;
	try {
		Span sp;
		sp.addNumber(4);
		sp.addNumber(2);}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
	
	// Test when the span is too small to calculate the shortest span
	std::cout << MAGENTA "\n[SPAN TOO SMALL TEST]" RESET << std::endl;
	try {
		Span sp(2);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	// Basic tests from the subject to demonstrate shortestSpan() and longestSpan()
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

	// Test for a large span
	std::cout << MAGENTA "\n[LARGE SPAN TEST]" RESET << std::endl;
	try {
		Span lsp = Span(10000);
		std::vector<int> list(10000);
		for (int i = 0; i < 10000; ++i)
			list[i] = i;
		
		lsp.addRange(list.begin(), list.end());
			
		std::cout << "Shortest span = " << lsp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << lsp.longestSpan() << std::endl; }
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	// Test for a large span but to small to hold the requested range
	std::cout << MAGENTA "\n[LARGE SPAN FULL TEST]" RESET << std::endl;
	try {
		Span lsp = Span(10000);
		std::vector<int> list(10000);
		for (int i = 0; i < 10000; ++i)
			list[i] = i;
		
		lsp.addNumber(42);
		lsp.addRange(list.begin(), list.end());}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
    return 0;
}
