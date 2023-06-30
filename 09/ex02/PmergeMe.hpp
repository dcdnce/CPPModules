#pragma once

#include <vector>
#include <list>
#include <ctime>


class PmergeMe {
	private:
	 	clock_t _startTime;
		size_t	_sequence_size;
		size_t	_trail;

		/* VECTOR */
		void	_makeSortedPairs(std::vector<std::pair<size_t, size_t> > & pairs);
		void	_insertionSort(std::vector<std::pair<size_t, size_t> > & pairs, size_t n);
		void	_mergeSort(std::vector<std::pair<size_t,size_t> >& pairs);
		void 	_computeJacobsthalSequence(std::vector<size_t> & jacobsthal_indexes, size_t const arrayLength);
		size_t	_binarySearch(std::vector<size_t> nums, size_t target);

		/* LIST */
		void	_makeSortedPairs(std::list<std::pair<size_t, size_t> > & pairs);
		void	_insertionSort(std::list<std::pair<size_t, size_t> > & pairs, size_t n);
		void	_mergeSort(std::list<std::pair<size_t,size_t> >& pairs);
		void 	_computeJacobsthalSequence(std::list<size_t> & jacobsthal_indexes, size_t const arrayLength);
		size_t	_binarySearch(std::list<size_t> nums, size_t target);

		size_t	_jacobsthal(size_t n);

		void	_startChrono();
		double	_endChrono();

	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		~PmergeMe();

		std::vector<size_t> vector_sequence;
		std::list<size_t> list_sequence;
		double	vector_duration;
		double	list_duration;

		void	sort();

		PmergeMe & operator=(PmergeMe const & rhs);
};
