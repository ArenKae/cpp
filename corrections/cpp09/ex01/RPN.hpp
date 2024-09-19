
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(const RPN & src);
		RPN & operator=(const RPN & other);
		~RPN(void);
		void case_add();
		void case_sub();
		void case_mul();
		void case_div();
		void calculator(std::string numbers);

	private:
		std::stack<int> _stack;
};

#endif