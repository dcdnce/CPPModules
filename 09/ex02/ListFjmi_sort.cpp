#include "ListFjmi.hpp"

#include <iostream>
#include <algorithm>

//https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
//ford-johnson-merge-insertion-sort
void ListFjmi::sort()
{
    _startChrono();
	_sequence_size = sequence.size();
	if (_sequence_size % 2)
	{
		_trail = sequence.back();
		sequence.pop_back();
	}

	// Make sorted pairs
	std::list<std::pair<size_t, size_t> > pairs = _makeSortedPairs();

	// Insertion Sort -> sort vector<pair> by second value
	_insertionSort(pairs, pairs.size());

	// Merge Sort -> insert unsorted side into sorted side
	_mergeSort(pairs);
   	_endChrono();
}

std::list<std::pair<size_t, size_t> > ListFjmi::_makeSortedPairs()
{
    std::list<std::pair<size_t, size_t> > pairs;

    std::list<size_t>::iterator it = sequence.begin();
    std::list<size_t>::iterator end = sequence.end();

    while (it != end && std::distance(it, end) >= 2)
    {
        std::pair<size_t, size_t> curr = std::make_pair(*it, *(++it));
        if (curr.first > curr.second)
            std::swap(curr.first, curr.second);
        pairs.push_back(curr);

        ++it;
    }

    return pairs;
}

void ListFjmi::_insertionSort(std::list<std::pair<size_t, size_t> >& pairs, size_t n)
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

void	ListFjmi::_mergeSort(std::list<std::pair<size_t,size_t> >& pairs)
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
	jacobsthal_indexes = _computeJacobsthalSequence(pending.size());

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

	sequence = sorted;
}

std::list<size_t>	ListFjmi::_computeJacobsthalSequence(size_t const arrayLength)
{
	std::list<size_t> jacobsthal_sequence;
	size_t	currValue;
	size_t currIndex = 3;


	for (; (currValue = _jacobsthal(currIndex)) < arrayLength - 1 ; currIndex++)
		jacobsthal_sequence.insert(jacobsthal_sequence.begin(), currValue);

	return (jacobsthal_sequence);
}

size_t ListFjmi::_jacobsthal(size_t n)
{
	if (n == 0)
		return (0);

	if (n == 1)
		return (1);

	return (_jacobsthal(n-1) + _jacobsthal(n-2) * 2);
}

size_t ListFjmi::_binarySearch(std::list<size_t> nums, size_t target)
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