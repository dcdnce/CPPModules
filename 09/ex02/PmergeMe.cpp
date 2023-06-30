#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

//https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
//ford-johnson-merge-insertion-sort
void PmergeMe::sort()
{
	_sequence_size = vector_sequence.size();
	if (_sequence_size % 2)
	{
		_trail = vector_sequence.back();
		vector_sequence.pop_back();
		list_sequence.pop_back();
	}

	_startChrono();
	std::vector<std::pair<size_t, size_t> > vector_pairs;
	_makeSortedPairs(vector_pairs);
	_insertionSort(vector_pairs, vector_pairs.size());
	_mergeSort(vector_pairs);
	vector_duration = _endChrono();

    _startChrono();
	std::list<std::pair<size_t, size_t> > list_pairs;
	_makeSortedPairs(list_pairs);
	_insertionSort(list_pairs, list_pairs.size());
	_mergeSort(list_pairs);
   	list_duration = _endChrono();
}

////////////
////////////
/* VECTOR */
////////////
////////////
void PmergeMe::_makeSortedPairs(std::vector<std::pair<size_t, size_t> > & pairs)
{
	for (size_t i = 0 ; i+1 < _sequence_size ; i += 2)
	{
		std::pair<size_t, size_t> curr = std::make_pair(vector_sequence[i], vector_sequence[i+1]);	
		if (curr.first > curr.second)
			std::swap(curr.first, curr.second);
		pairs.push_back(curr);
	}
}

void	PmergeMe::_insertionSort(std::vector<std::pair<size_t, size_t> > & pairs, size_t n)
{
	if (n <= 1)
		return ;

	_insertionSort(pairs, n-1);

	std::pair<size_t, size_t> to_insert = pairs[n - 1];	
	int i = n - 2;

	while (i >= 0 && pairs[i].second > to_insert.second)
	{
		pairs[i+1] = pairs[i];
		i--;
	}

	pairs[i+1] = to_insert;
}


void	PmergeMe::_mergeSort(std::vector<std::pair<size_t,size_t> >& pairs)
{
	std::vector<size_t> pending;
	std::vector<size_t> sorted;
	std::vector<size_t> jacobsthal_indexes;
	std::vector<size_t>	used_indexes;
	bool	jacobsthal_sequence_used = false;
	size_t to_insert;

	for (size_t i = 0 ; i < pairs.size() ; i++)
	{
		sorted.push_back(pairs[i].second);
		pending.push_back(pairs[i].first);
	}
	
	// Insert 1st elem of pending vector -> it is smaller than the first element of sorted vector
	sorted.insert(sorted.begin(), pending[0]);

	// Determine insertion order with Jacobsthal sequence -> because binary search is more effective w/ power of 2 - 1
	_computeJacobsthalSequence(jacobsthal_indexes, pending.size());

	// Sort
	for (size_t i = 1 ; i < pending.size() ;)
	{
		// Use jacobsthal index if possible
		if (!jacobsthal_sequence_used && jacobsthal_indexes.size())
		{
			used_indexes.push_back(jacobsthal_indexes.back());
			to_insert = pending[jacobsthal_indexes.back()];
			jacobsthal_indexes.pop_back();
			jacobsthal_sequence_used = true;
		}
		// Else use first found index
		else
		{
			while(std::find(used_indexes.begin(), used_indexes.end(), i) != used_indexes.end())
				i++;
			if (i >= pending.size())
				break ;
			used_indexes.push_back(i);
			to_insert = pending[i];
			jacobsthal_sequence_used = false;
		}

		// Insert element in sorted array
		size_t	to_insert_index = _binarySearch(sorted, to_insert);
		sorted.insert(sorted.begin() + to_insert_index, to_insert);
	}

	// Insert trail if it exists
	if (_sequence_size % 2)
		sorted.insert(sorted.begin() + _binarySearch(sorted, _trail), _trail);

	vector_sequence = sorted;
}

void	PmergeMe::_computeJacobsthalSequence(std::vector<size_t> & jacobsthal_indexes, size_t const arrayLength)
{
	size_t	currValue;
	size_t currIndex = 3;


	for (; (currValue = _jacobsthal(currIndex)) < arrayLength - 1 ; currIndex++)
		jacobsthal_indexes.insert(jacobsthal_indexes.begin(), currValue);
}

size_t PmergeMe::_jacobsthal(size_t n)
{
	if (n == 0)
		return (0);

	if (n == 1)
		return (1);

	return (_jacobsthal(n-1) + _jacobsthal(n-2) * 2);
}

size_t	PmergeMe::_binarySearch(std::vector<size_t> nums, size_t target)
{
	int lo = 0;
	int mid;
	int hi = nums.size() - 1;

	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (target == nums[mid])
			return (mid);
		else if (target < nums[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	return (lo);
}

//////////
//////////
/* LIST */
//////////


void	PmergeMe::_makeSortedPairs(std::list<std::pair<size_t, size_t> > & pairs)
{
    std::list<size_t>::iterator it = list_sequence.begin();
    std::list<size_t>::iterator end = list_sequence.end();

    while (it != end && std::distance(it, end) >= 2)
    {
        std::pair<size_t, size_t> curr = std::make_pair(*it, *(++it));
        if (curr.first > curr.second)
            std::swap(curr.first, curr.second);
        pairs.push_back(curr);

        ++it;
    }
}

void PmergeMe::_insertionSort(std::list<std::pair<size_t, size_t> >& pairs, size_t n)
{
    if (n <= 1)
        return;

    _insertionSort(pairs, n - 1);

    std::list<std::pair<size_t, size_t> >::iterator it = pairs.begin();
    std::advance(it, n - 1);
    std::list<std::pair<size_t, size_t> >::iterator pos = pairs.begin();
    std::advance(pos, n - 2);

    std::pair<size_t, size_t> to_insert = *it;
	int	i = n - 2;

    while (i >= 0 && pos->second > to_insert.second)
    {
        *it = *pos;
        --it;
        --pos;
		i--;
    }

    *it = to_insert;
}

void	PmergeMe::_mergeSort(std::list<std::pair<size_t,size_t> >& pairs)
{
	std::list<size_t> pending;
	std::list<size_t> sorted;
	std::list<size_t> jacobsthal_indexes;
	std::list<size_t>	used_indexes;
	bool	jacobsthal_sequence_used = false;
	size_t to_insert;

    for(std::list<std::pair<size_t, size_t> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->second);
		pending.push_back(it->first);
	}
	
	// Insert 1st elem of pending vector -> it is smaller than the first element of sorted vector
	sorted.insert(sorted.begin(), *(pending.begin()));

	// Determine insertion order with Jacobsthal sequence -> because binary search is more effective w/ power of 2 - 1
	_computeJacobsthalSequence(jacobsthal_indexes ,pending.size());

	// Sort
	for (size_t i = 1 ; i < pending.size() ;)
	{
		// Use jacobsthal index if possible
		if (!jacobsthal_sequence_used && jacobsthal_indexes.size())
		{
			used_indexes.push_back(jacobsthal_indexes.back());
			std::list<size_t>::iterator it = pending.begin();
			std::advance(it, jacobsthal_indexes.back());
			to_insert = *it;
			jacobsthal_indexes.pop_back();
			jacobsthal_sequence_used = true;
		}
		// Else use first found index
		else
		{
			while(std::find(used_indexes.begin(), used_indexes.end(), i) != used_indexes.end())
				i++;
			if (i >= pending.size())
				break ;
			used_indexes.push_back(i);
			std::list<size_t>::iterator it = pending.begin();
			std::advance(it, i);
			to_insert = *it;
			jacobsthal_sequence_used = false;
		}

		// Insert element in sorted array
		std::list<size_t>::iterator it = sorted.begin();
		std::advance(it, _binarySearch(sorted, to_insert));
		sorted.insert(it, to_insert);
	}

	// Insert trail if it exists
	if (_sequence_size % 2)
	{
		std::list<size_t>::iterator it = sorted.begin();
		std::advance(it, _binarySearch(sorted, _trail));
		sorted.insert(it, _trail);
	}

	list_sequence = sorted;
}

void 	PmergeMe::_computeJacobsthalSequence(std::list<size_t> & jacobsthal_indexes, size_t const arrayLength)
{
	size_t	currValue;
	size_t currIndex = 3;


	for (; (currValue = _jacobsthal(currIndex)) < arrayLength - 1 ; currIndex++)
		jacobsthal_indexes.insert(jacobsthal_indexes.begin(), currValue);
}

size_t PmergeMe::_binarySearch(std::list<size_t> nums, size_t target)
{
    int lo = 0;
    int mid;
    int hi = nums.size() - 1;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        std::list<size_t>::iterator it = nums.begin();
        std::advance(it, mid);

        if (target == *it)
			  return (mid);
        else if (target < *it)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

/* OTHER */
PmergeMe::PmergeMe()
{
	vector_sequence.clear();
	list_sequence.clear();
}

PmergeMe::PmergeMe(PmergeMe const & src) {*this = src;}

PmergeMe::~PmergeMe(){}

void	PmergeMe::_startChrono()
{
	_startTime = clock();
}

double	PmergeMe::_endChrono()
{
	return ((((double)(clock() - _startTime)) / CLOCKS_PER_SEC));
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	this->vector_sequence = rhs.vector_sequence;
	this->_sequence_size = rhs.vector_sequence.size();
	if (_sequence_size % 2)
	{
		_trail = vector_sequence.back();
		vector_sequence.pop_back();
		list_sequence.pop_back();
	}
	return *this;
}
