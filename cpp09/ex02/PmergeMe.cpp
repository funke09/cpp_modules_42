#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : size(0), sorted(false)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char **argv) : size(argc - 1), sorted(false)
{
	vector = _parseArgsVector(argc,argv);
	_verifyDuplicates();
	deque = _parseArgsDeque(argc,argv);

	_printBeforeAfter();

	double tBegin = _getTime();
	_mergeInsertSort(vector);
	TimeVector = _deltaTime(tBegin);

	tBegin = _getTime();
	_mergeInsertSort(deque);
	TimeDeque = _deltaTime(tBegin);

	sorted = true;
	_printBeforeAfter();

	_printTime("vector");
	_printTime("deque");
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj)
	{
		this->size = obj.size;
		this->sorted = obj.sorted;
		this->vector = obj.vector;
		this->deque = obj.deque;
		this->TimeVector = obj.TimeVector;
		this->TimeDeque = obj.TimeDeque;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const PmergeMe& i)
{
	o 
		<< "Vector delta time: " << i.getVectorTime() << std::endl
		<< "Deque delta time: " << i.getDequeTime();
	return o;
}

/*
** Getters
*/

double	PmergeMe::getVectorTime(void) const
{
	return (this->TimeVector);
}
double	PmergeMe::getDequeTime(void) const
{
	return (this->TimeDeque);
}

/*
** Parse and verify input
*/

std::vector<int> PmergeMe::_parseArgsVector(int argc, char **argv)
{
	std::vector<int>	args;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int value = atoi(arg.c_str());
		if (value <= 0)
			throw invalidArgumentError();
		args.push_back(value);
	}
	return (args);
}

std::deque<int> PmergeMe::_parseArgsDeque(int argc, char **argv)
{
	std::deque<int>	args;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		int value = atoi(arg.c_str());
		if (value <= 0)
			throw invalidArgumentError();
		args.push_back(value);
	}
	return (args);
}

void PmergeMe::_verifyDuplicates(void)
{
	std::set<int> numSet;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
		int num = *it;
		if (numSet.find(num) != numSet.end())
			throw duplicatesError();
		numSet.insert(num);
	}
}

/*
** Sort
*/

template <typename T>
void	PmergeMe::_mergeInsertSort(T& container)
{
	const int threshold = 16;
	const int size = container.size();
	if (size < 2)
		return ;
	if (size < threshold)
	{
		for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		{
			typename T::iterator j = i;
			while (j != container.begin() && *(j - 1) > *j)
			{
				std::swap(*j, *(j - 1));
				--j;
			}
		}
		return ;
	}
	typename T::iterator middle = container.begin() + size / 2;
	T left(container.begin(), middle);
	T right(middle, container.end());
	_mergeInsertSort(left);
	_mergeInsertSort(right);
	typename T::iterator i = left.begin();
	typename T::iterator j = right.begin();
	typename T::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}
	while (i != left.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

/*
** Manage time
*/

double	PmergeMe::_getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::_deltaTime(long long time)
{
	if (time > 0)
		return (_getTime() - time);
	return (0);
}

/*
** Printers
*/

void	PmergeMe::_printBeforeAfter(void)
{
	if (sorted == false)
		std::cout << "Before: ";
	else
		std::cout << "After:  ";
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::_printTime(std::string vectorDeque) const
{
	double delta;
	if (vectorDeque == "vector")
		delta = TimeVector;
	else if (vectorDeque == "deque")
		delta = TimeDeque;
	else
		throw containerTypeError();
	std::cout 
		<< "Time to process a range of " << size 
		<< " elements with std::" << vectorDeque << ": "
		<< std::fixed << std::setprecision(5) << delta << " ms" << std::endl;
}