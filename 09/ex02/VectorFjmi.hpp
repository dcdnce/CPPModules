#pragma once

#include <vector>
#include <ctime>


class VectorFjmi {
	private:
	 	clock_t _startTime, _endTime;
		size_t	_sequence_size;
		size_t	_trail;

		std::vector<std::pair<size_t, size_t> >	_makeSortedPairs();
		void	_insertionSort(std::vector<std::pair<size_t, size_t> > & pairs, size_t n);
		void	_mergeSort(std::vector<std::pair<size_t,size_t> >& pairs);
		std::vector<size_t>	_computeJacobsthalSequence(size_t const arrayLength);
		size_t	_jacobsthal(size_t n);
		size_t	_binarySearch(std::vector<size_t> nums, size_t target);

		void	_startChrono();
		void	_endChrono();

	public:
		VectorFjmi();
		VectorFjmi(VectorFjmi const & src);
		~VectorFjmi();

		std::vector<size_t> sequence;

		void	parse(int const ac, char *av[]);
		void	sort();
		void	printDuration();

		VectorFjmi operator=(VectorFjmi const & rhs);
};
