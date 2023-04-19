#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream> 
#include <stdlib.h> 
#include <iomanip> 
#include <sys/time.h> 
#include <vector> 
#include <deque> 
#include <set> 

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& obj);
		~PmergeMe();

		double	getVectorTime(void) const;
		double	getDequeTime(void) const;

		PmergeMe&	operator=(const PmergeMe& obj);

	private:
		int					size;
		bool				sorted;
		std::vector<int>	vector;
		std::deque<int>		deque;
		double				TimeVector;
		double				TimeDeque;

		std::vector<int>	parseArgsVector(int argc, char **argv);
		std::deque<int>		parseArgsDeque(int argc, char **argv);

		void				isDuplicates(void);

		void				print(void);
		void				printTime(std::string vectorDeque) const;

		template <typename T>
		void				Sort(T& container);
	
		double				getTime(void);
		double				Timer(long long time);
		class ArgumentError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: invalid argument");
				}
		};

		class DuplicatesError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: duplicates not allowed");
				}
		};

		class ContainerError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the container choosen is not vector or deque");
				}
		};
};

std::ostream&	operator<<(std::ostream& out, const PmergeMe& Pmerg);

#endif