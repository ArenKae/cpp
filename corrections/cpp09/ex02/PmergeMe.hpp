#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe & src);
		PmergeMe & operator=(const PmergeMe & other);
		~PmergeMe(void);
		std::vector<int> sort_vector();
		void merge_vectors(char **numbers);
		std::vector<int> get_vector();
		std::deque<int> sort_deq();
		void merge_deq(char **numbers);

	private:
		std::vector<int> _vec;
		std::vector<int> _vec2;
		std::deque<int> _deq;
		std::deque<int> _deq2;

};

#endif