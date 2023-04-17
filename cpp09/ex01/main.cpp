#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	RPN	RPN;

	if (ac != 2)
	{
		std::cerr
			<< "Usage: " << av[0] << " <RPN>" << std::endl;
	}
	else
	{
		try
		{
			RPN.ReversePolishNotation(av[1]);
			std::cout << RPN << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
