
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe P1;
	if (argc < 3)
	{
		std::cout << "Error. Minimum 2 numbers." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				std::cout << "Error." << std::endl;
				return (1);
			}
			else if (std::atof(argv[i]) > 2147483647)
			{
				std::cout << "Error. Number bigger than MAXINT." << std::endl;
				return (1);
			}
			j++;
		}
	}
    std::cout << "Before: ";
	int i = 0;
	while (++i < argc)
	    std::cout << argv[i] << " ";
    std::cout << std::endl;
	
	clock_t beginning_vec = clock();
	P1.merge_vectors(argv);
	clock_t end_vec = clock();

	clock_t beginning_deq = clock();
	P1.merge_deq(argv);
	clock_t end_deq = clock();
	
	std::cout << "After: ";
	std::vector<int> vector = P1.get_vector();

	for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
	double time_vec = static_cast<double>(end_vec - beginning_vec) / CLOCKS_PER_SEC * 1000;
	double time_deq = static_cast<double>(end_deq - beginning_deq) / CLOCKS_PER_SEC * 1000;

	std::cout << "\nTime to process a range of " << (argc - 1) << " elements with std::vector container: " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque container: " << time_deq << " us" << std::endl;	return (0);
}