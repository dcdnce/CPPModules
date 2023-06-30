#include "VectorFjmi.hpp"

#include <iostream>
#include <algorithm>

//https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
//ford-johnson-merge-insertion-sort
void VectorFjmi::sort()
{
	_startChrono();

	_sequence_size = sequence.size();
	if (_sequence_size % 2)
	{
		_trail = sequence.back();
		sequence.pop_back();
	}

	// Make sorted pairs
	std::vector<std::pair<size_t, size_t> > pairs = _makeSortedPairs();

	// Insertion Sort -> sort vector<pair> by second value
	_insertionSort(pairs, pairs.size());

	// Merge Sort -> insert unsorted side into sorted side
	_mergeSort(pairs);

	_endChrono();
}

std::vector<std::pair<size_t, size_t> >	VectorFjmi::_makeSortedPairs()
{
	std::vector<std::pair<size_t, size_t> > pairs;

	for (size_t i = 0 ; i+1 < _sequence_size ; i += 2)
	{
		std::pair<size_t, size_t> curr = std::make_pair(sequence[i], sequence[i+1]);	
		if (curr.first > curr.second)
			std::swap(curr.first, curr.second);
		pairs.push_back(curr);
	}

	return (pairs);
}

void	VectorFjmi::_insertionSort(std::vector<std::pair<size_t, size_t> > & pairs, size_t n)
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


void	VectorFjmi::_mergeSort(std::vector<std::pair<size_t,size_t> >& pairs)
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
	jacobsthal_indexes = _computeJacobsthalSequence(pending.size());

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

	sequence = sorted;
}

std::vector<size_t>	VectorFjmi::_computeJacobsthalSequence(size_t const arrayLength)
{
	std::vector<size_t> jacobsthal_sequence;
	size_t	currValue;
	size_t currIndex = 3;


	for (; (currValue = _jacobsthal(currIndex)) < arrayLength - 1 ; currIndex++)
		jacobsthal_sequence.insert(jacobsthal_sequence.begin(), currValue);

	return (jacobsthal_sequence);
}

size_t VectorFjmi::_jacobsthal(size_t n)
{
	if (n == 0)
		return (0);

	if (n == 1)
		return (1);

	return (_jacobsthal(n-1) + _jacobsthal(n-2) * 2);
}


size_t	VectorFjmi::_binarySearch(std::vector<size_t> nums, size_t target)
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