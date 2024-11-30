/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:02:02 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 06:58:12 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

PmergeMe::PmergeMe() {};
	
PmergeMe::PmergeMe(const PmergeMe &src) {(void)src;};

PmergeMe::~PmergeMe() {};

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return *this;
}

/**********************************/
/*********[ LIST SORTING ]*********/
/**********************************/

// Sort the list by spliting it into single elements sublists before merging them into a sorted one.
void PmergeMe::sortList(std::list<int>& lst)
{
	if (lst.size() <= 1)
		return;

	// Create 2 sublists to split the sequence in half
	std::list<int> left, right;
	size_t mid = lst.size() / 2;
	size_t count = 0;

	// Parse the sequence with an iterator to fill the 2 sublists
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		if (count++ < mid)
			left.push_back(*it);
		else
			right.push_back(*it);
	}

	// Recursively split the 2 newly created sublists until we get single elements
	sortList(left);
	sortList(right);

	lst.clear(); // Clear the unsorted list and reuse it for the result
	mergeSortList(left, right, lst); // Compare the 2 sublists and merge them into a sorted one.
}

// Merge the single elements into a new sorted pair. Then, each pair is merged by
// comparing each elements. Repeat until the final merge where everything is sorted.
void PmergeMe::mergeSortList(std::list<int> &left, std::list<int> &right, std::list<int> &result)
{
	// Create an iterator to parse each sublist
	std::list<int>::iterator itL = left.begin(), itR = right.begin();

	// Compare the numbers in each list and push the smallest one to result until one sublist reach its end
	while (itL != left.end() && itR != right.end())
	{
		if (*itL <= *itR) result.push_back(*itL++);
		else result.push_back(*itR++);
	}

	// Any remaining elements are appended at the end.
	while (itL != left.end()) result.push_back(*itL++);
	while (itR != right.end()) result.push_back(*itR++);
}

