
#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "Default constructor called." << std::endl;
}

RPN::RPN(const RPN & src)
{
	*this = src;
	// std::cout << "Copy constructor called." << std::endl;
}

RPN &RPN::operator=(const RPN & other)
{
	// std::cout << "Copy assignement operator called." << std::endl;
	this->_stack = other._stack;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "Destructor called." << std::endl;
}

void RPN::case_add()
{
	int tmp1 = _stack.top();
	_stack.pop();
	int tmp2 = _stack.top();
	int res = tmp2 + tmp1;
	_stack.pop();
	_stack.push(res);
}

void RPN::case_sub()
{
	int tmp1 = _stack.top();
	_stack.pop();
	int tmp2 = _stack.top();
	int res = tmp2 - tmp1;
	_stack.pop();
	_stack.push(res);
}

void RPN::case_mul()
{
	int tmp1 = _stack.top();
	_stack.pop();
	int tmp2 = _stack.top();
	int res = tmp2 * tmp1;
	_stack.pop();
	_stack.push(res);
}

void RPN::case_div()
{
	int tmp1 = _stack.top();
	_stack.pop();
	int tmp2 = _stack.top();
	if (tmp1 == 0)
	{
		std::cout << "Error. Cannot divide by 0." << std::endl;
		exit(1) ;
	}
	if (tmp2 == 0)
	{
		std::cout << "Error. Cannot divide 0." << std::endl;
		exit(1) ;
	}
	int res = tmp2 / tmp1;
	_stack.pop();
	_stack.push(res);
}

void RPN::calculator(std::string numbers)
{
	if (numbers.empty())
	{
		std::cout << "Error. No numbers detected." << std::endl;
		return ;
	}
	if(numbers[numbers.size() - 1] != 42 && numbers[numbers.size() - 1] != 43 && numbers[numbers.size() - 1] != 45
	&& numbers[numbers.size() - 1] != 47 && numbers[numbers.size() - 1] != 32)
	{
		std::cout << "Error. Bad input " << numbers << std::endl;
		return ;
	}
	size_t i = 0;
	int j = 0;
	int count = 0;
	while (numbers[i])
	{
		if (isdigit(numbers[i]))
			_stack.push(numbers[i] - 48);
		else if (numbers[i] == 42 || numbers[i] == 43 || numbers[i] == 45 || numbers[i] == 47 || numbers[i] == 32)
		{
			j = numbers[i];
			if (_stack.size() < 2 && i != numbers.find_last_of("0123456789 ", i))
			{
				std::cout << "Error. Could not calculate." << std::endl;
				return ;
			}
			switch(j)
			{
				case '+':
					case_add();
				count++;
				break ;
				case '-':
					case_sub();
				count++;
				break ;
				case '*':
					case_mul();
				count++;
				break ;
				case '/':
					case_div();
				count++;
				break ;
				case ' ':
					break ;
			}
		}
		else
		{
			std::cout << "Error. Bad input " << numbers << std::endl;
			return ;
		}
		i++;
	}
	if (count == 0)
	{
		std::cout << "Error. Bad input " << numbers << std::endl;
		return ;
	}
	else if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
}
