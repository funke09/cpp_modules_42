
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
		RPN(const RPN& obj);
		~RPN();
		RPN&	operator=(const RPN& obj);


		void	ReversePolishNotation(const std::string &RPN);
		bool	isOperator(char c);
		void	calculator(int first, int second, char operation);

		int		getResult(void) const;

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

		class DivisionByZero : public std::exception
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