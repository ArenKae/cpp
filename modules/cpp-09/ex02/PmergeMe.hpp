/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:02:06 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 06:34:27 by acosi            ###   ########.fr       */
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
		void mergeInsertSortVector(std::vector<int> &vec, size_t left, size_t right);
    	void mergeVector(std::vector<int> &vec, size_t left, size_t mid, size_t right);
    	void mergeSortList(std::list<int> &left, std::list<int> &right, std::list<int> &lst_sorted);
};

#endif