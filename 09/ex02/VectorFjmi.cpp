#include "VectorFjmi.hpp"
#include <string>
#include <iostream>

VectorFjmi::VectorFjmi() {
	sequence.clear();
}
VectorFjmi::VectorFjmi(VectorFjmi const & src) {*this = src;}
VectorFjmi::~VectorFjmi() {}

VectorFjmi VectorFjmi::operator=(VectorFjmi const & rhs)
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

void	VectorFjmi::_startChrono()
{
	_startTime = clock();
}

void	VectorFjmi::_endChrono()
{
	_endTime = clock();
}

void	VectorFjmi::printDuration()
{
	double duration = (((double)(_endTime - _startTime)) / CLOCKS_PER_SEC) * 1000000.0;

	std::cout << "Time to process a range of " << _sequence_size << " with std::vector : " << duration << " µs" << std::endl;
}