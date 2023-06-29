#pragma once

#include <list>
#include <ctime>


class ListFjmi {
	private:
	 	clock_t _startTime, _endTime;
		size_t	_sequence_size;
		size_t	_trail;

		std::list<std::pair<size_t, size_t> >	_makeSortedPairs();
		void	_insertionSort(std::list<std::pair<size_t, size_t> > & pairs, size_t n);
		void	_mergeSort(std::list<std::pair<size_t,size_t> >& pairs);
		std::list<size_t>	_computeJacobsthalSequence(size_t const arrayLength);
		size_t	_jacobsthal(size_t n);
		size_t	_binarySearch(std::list<size_t> nums, size_t target);

		void	_startChrono();
		void	_endChrono();

	public:
		ListFjmi();
		ListFjmi(ListFjmi const & src);
		~ListFjmi();

		std::list<size_t> sequence;

		void	parse(int const ac, char *av[]);
		void	sort();
		void	printDuration();

		ListFjmi operator=(ListFjmi const & rhs);
};
