
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h> 

class RPN
{
	public:
		RPN();
		RPN(const RPN& object);
		~RPN();
		RPN&	operator=(const RPN& object);


		void	ReversePolishNotation(const std::string &RPN);
		bool	isOperator(char c);
		void	calculator(int first, int second, char operation);

		int		getResult() const;

	private:
		std::stack<int> stack;
		int				result;
		class NeededOperations : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: number of operations is not enough.");
				}
		};

		class invalidArgs : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: invalid args");
				}
		};

		class tooManyOperators : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: too many operators");
				}
		};

		class DivisionError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: division by zero");
				}
		};
};

std::ostream&	operator<<(std::ostream& Opr, const RPN& RPN);


#endif