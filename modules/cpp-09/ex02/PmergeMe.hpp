/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:02:06 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 07:27:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>		// atoi()
#include <sstream>		// string stream manipulation
#include <stdexcept>

class PmergeMe
{
	public:
		// Orthodox Canoncial Form
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &src);

		// Main member functions
		void sortVector(std::vector<int> &vec);
		void sortList(std::list<int> &lst);

	private:
		void mergeSortVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result);
    	void mergeSortList(std::list<int> &left, std::list<int> &right, std::list<int> &lst_sorted);
};

#endif