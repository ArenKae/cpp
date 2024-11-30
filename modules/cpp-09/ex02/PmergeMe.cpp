/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:02:02 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 07:29:30 by acosi            ###   ########.fr       */
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

	// Create 2 sublists to split the vec in half
	std::list<int> left, right;
	size_t mid = lst.size() / 2;
	size_t count = 0;

	// Parse the vec with an iterator to fill the 2 sublists
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

/**********************************/
/********[ VECTOR SORTING ]********/
/**********************************/

void PmergeMe::sortVector(std::vector<int> &vec)
{
    if (vec.size() <= 1)
		return;

    std::vector<int> left, right;
    size_t mid = vec.size() / 2;
    size_t count = 0;

    for (size_t i = 0; i < vec.size(); ++i)
	{
        if (count++ < mid)
			left.push_back(vec[i]);
        else
			right.push_back(vec[i]);
    }

    sortVector(left);
    sortVector(right);

    vec.clear();
    mergeSortVector(left, right, vec);
}

void PmergeMe::mergeSortVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result)
{
    size_t itL = 0, itR = 0;

    while (itL < left.size() && itR < right.size())
	{
        if (left[itL] <= right[itR])
			result.push_back(left[itL++]);
        else
			result.push_back(right[itR++]);
    }

    while (itL < left.size()) result.push_back(left[itL++]);
    while (itR < right.size()) result.push_back(right[itR++]);
}

