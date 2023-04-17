#include "RPN.hpp"

RPN::RPN() : result(0)
{}

RPN::RPN(const RPN& object)
{
	*this = object;
	return ;
}

RPN::~RPN()
{}

RPN& RPN::operator=(const RPN& object)
{
	if (this != &object)
	{
		this->stack = object.stack;
		this->result = object.result;
	}
	return (*this);
}

void	RPN::ReversePolishNotation(const std::string &RPN)
{
	std::string args;

	for (std::size_t i = 0; i < RPN.length(); i++)
	{
		char c = RPN[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
			args += c;
		else if (isOperator(c))
		{
			if (stack.size() < 2)
				throw NeededOperations();
			int second = stack.top();
			stack.pop();
			int first = stack.top();
			stack.pop();
			calculator(first, second, c);
		}
		else
			throw invalidArgs();
		if (!args.empty())
		{
			stack.push(atoi(args.c_str()));
			args.clear();
		}
	}
	if (stack.size() != 1)
		throw tooManyOperators();
	result = stack.top();
	stack.pop();
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::calculator(int first, int second, char operation)
{
	switch (operation)
	{
		case '+':
			stack.push(first + second);
			break;
		case '-':
			stack.push(first - second);
			break;
		case '*':
			stack.push(first * second);
			break;
		case '/':
			if (second == 0)
				throw DivisionError();
			stack.push(first / second);
			break;
	}
}

int	RPN::getResult() const
{
	return (this->result);
}

std::ostream&	operator<<(std::ostream& OP, const RPN& RPN)
{
	OP << RPN.getResult();
	return OP;
}