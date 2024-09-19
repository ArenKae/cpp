
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error. Wrong number of arguments." << std::endl;
		return (1);
	}
	RPN RP1;
	RP1.calculator(argv[1]);
	return (0);
}