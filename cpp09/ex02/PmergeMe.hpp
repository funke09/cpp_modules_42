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

		std::vector<int>	_parseArgsVector(int argc, char **argv);
		std::deque<int>		_parseArgsDeque(int argc, char **argv);

		void				_verifyDuplicates(void);

		void				_printBeforeAfter(void);
		void				_printTime(std::string vectorDeque) const;

		template <typename T>
		void				_mergeInsertSort(T& container);
	
		double				_getTime(void);
		double				_deltaTime(long long time);

	protected:

		class invalidArgumentError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: invalid argument");
				}
		};

		class duplicatesError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: duplicates are forbidden");
				}
		};

		class containerTypeError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: container choosen to print is not vector or deque");
				}
		};
};

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i);

#endif