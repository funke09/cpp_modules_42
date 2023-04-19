#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : size(0), sorted(false)
{
	return ;
}

PmergeMe::PmergeMe(int ac, char **av) : size(ac - 1), sorted(false)
{
      for(int i=1; i<ac; i++) {
        for(int j=0; av[i][j]!='\0'; j++) {
            if(!isdigit(av[i][j]) && av[i][j] != '+') {
                throw std::invalid_argument("Invalid argument: all arguments must be numbers.");
            }
        }
    }
	vector = parseArgsVector(ac,av);
	isDuplicates();
	deque = parseArgsDeque(ac,av);

	print();

	double tBegin = getTime();
	Sort(vector);
	TimeVector = Timer(tBegin);

	tBegin = getTime();
	Sort(deque);
	TimeDeque = Timer(tBegin);

	sorted = true;
	print();

	printTime("vector");
	printTime("deque");
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& object)
{
	*this = object;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& object)
{
	if (this != &object)
	{
		this->vector = object.vector;
		this->deque = object.deque;
		this->size = object.size;
		this->sorted = object.sorted;
		this->TimeDeque = object.TimeDeque;
		this->TimeVector = object.TimeVector;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const PmergeMe& Pmerg)
{
	out 
		<< "Vector time: " << Pmerg.getVectorTime() << std::endl
		<< "Deque time: " << Pmerg.getDequeTime();
	return out;
}


double	PmergeMe::getVectorTime() const
{
	return (this->TimeVector);
}
double	PmergeMe::getDequeTime() const
{
	return (this->TimeDeque);
}

std::vector<int> PmergeMe::parseArgsVector(int ac, char **av)
{
	std::vector<int>	args;
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];
		int value = atoi(arg.c_str());
		if (value < 0)
			throw ArgumentError();
		args.push_back(value);
	}
	return (args);
}

std::deque<int> PmergeMe::parseArgsDeque(int ac, char **av)
{
	std::deque<int>	args;
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];
		int value = atoi(arg.c_str());
		if (value < 0)
			throw ArgumentError();
		args.push_back(value);
	}
	return (args);
}

void PmergeMe::isDuplicates()
{
	std::set<int> numberSet;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
		int number = *it;
		if (numberSet.find(number) != numberSet.end())
			throw DuplicatesError();
		numberSet.insert(number);
	}
}


template <typename T>
void	PmergeMe::Sort(T& container)
{
	const int begin = 16;
	const int size = container.size();
	if (size < 2)
		return ;
	if (size < begin)
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
	typename T::iterator tmp = container.begin() + size / 2;
	T prev(container.begin(), tmp);
	T next(tmp, container.end());
	Sort(prev);
	Sort(next);
	typename T::iterator i = prev.begin();
	typename T::iterator j = next.begin();
	typename T::iterator k = container.begin();
	while (i != prev.end() && j != next.end())
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
	while (i != prev.end())
	{
		*k = *i;
		++i;
		++k;
	}
	while (j != next.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

double	PmergeMe::getTime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double	PmergeMe::Timer(long long time)
{
	if (time > 0)
		return (getTime() - time);
	return (0);
}

void	PmergeMe::print(void)
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

void	PmergeMe::printTime(std::string vectorDeque) const
{
	double currentTime;
	if (vectorDeque == "vector")
		currentTime = TimeVector;
	else if (vectorDeque == "deque")
		currentTime = TimeDeque;
	else
		throw ContainerError();
	std::cout << "Time to process a range of " << size 
		<< " elements with std::" << vectorDeque << ": "
		<< std::fixed << std::setprecision(5) << currentTime << " ms" << std::endl;
}