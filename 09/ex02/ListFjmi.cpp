#include "ListFjmi.hpp"
#include <string>
#include <iostream>

ListFjmi::ListFjmi() {
	sequence.clear();
}
ListFjmi::ListFjmi(ListFjmi const & src) {*this = src;}
ListFjmi::~ListFjmi() {}

ListFjmi ListFjmi::operator=(ListFjmi const & rhs)
{
	this->sequence = rhs.sequence;
	this->_sequence_size = sequence.size();
	if (_sequence_size % 2)
	{
		_trail = sequence.back();
		sequence.pop_back();
	}
	return *this;
}

void	ListFjmi::_startChrono()
{
	_startTime = clock();
}

void	ListFjmi::_endChrono()
{
	_endTime = clock();
}

void	ListFjmi::printDuration()
{
	double duration = (((double)(_endTime - _startTime)) / CLOCKS_PER_SEC) * 1000000.0;

	std::cout << "Time to process a range of " << _sequence_size << " with std::list : " << duration << " µs" << std::endl;
}