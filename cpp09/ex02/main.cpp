#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Usage " << av[0] << "random numbers less than 10." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe input(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}