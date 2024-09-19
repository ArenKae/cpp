
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	// std::cout << "Default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe & src)
{
	*this = src;
	// std::cout << "Copy constructor called." << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe & other)
{
	// std::cout << "Copy assignement operator called." << std::endl;
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_vec2 = other._vec2;
		this->_deq = other._deq;
		this->_deq2 = other._deq2;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor called." << std::endl;
}

std::vector<int> PmergeMe::sort_vector()
{
	std::vector<int> tmp;
	// std::vector<int>::iterator it = _vec.begin();
    if (_vec.size() == 1)
	{
		tmp.push_back(_vec.front());
		_vec.pop_back();
        return (tmp);
	}
    std::vector<int>::iterator it = _vec.end();
    it--;
    tmp.push_back(*it);
    _vec.pop_back();
    sort(tmp.begin(), tmp.end());
    return (tmp);
}

void PmergeMe::merge_vectors(char **numbers)
{
	int i = -1;
	while (numbers[++i])
	{
		int num = atoi(numbers[i]);
		_vec.push_back(num);
	}
	while( _vec.size() > 1)
    {
		std::vector<int> tmp = sort_vector();
        std::vector<int> merged;
        std::merge(tmp.begin(), tmp.end(), _vec2.begin(), _vec2.end(), std::back_inserter(merged));
        _vec2 = merged;
    }
	return ;
}

std::vector<int> PmergeMe::get_vector()
{
	return (this->_vec2);
}

std::deque<int> PmergeMe::sort_deq()
{
    std::deque<int> tmp;
    if (_deq.size() == 1)
	{
    	tmp.push_back(_deq.front());
   	 	_deq.pop_back();
        return (tmp);
	}
    std::deque<int>::iterator it = _deq.end();
    it--;
    tmp.push_back(*it);
    _deq.pop_back();
    sort(tmp.begin(), tmp.end());
    return (tmp);
}

void PmergeMe::merge_deq(char **numbers)
{
	int i = -1;
	while (numbers[++i])
	{
		int num = atoi(numbers[i]);
		_deq.push_back(num);
	}
	while(_deq.size() > 1)
    {
		std::deque<int> tmp = sort_deq();
        std::deque<int> merged;
        std::merge(tmp.begin(), tmp.end(), _deq2.begin(), _deq2.end(), std::back_inserter(merged));
        _deq2 = merged;
    }
	return ;
}

