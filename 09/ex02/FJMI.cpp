#include "FJMI.hpp"
#include <string>
#include <iostream>

FJMI::FJMI() {
	sequence.clear();
}
FJMI::FJMI(FJMI const & src) {*this = src;}
FJMI::~FJMI() {}

FJMI FJMI::operator=(FJMI const & rhs)
{
	(void)rhs;
	return *this;
}

void	FJMI::startChrono()
{
	_startTime = clock();
}

void	FJMI::endChrono()
{
	_endTime = clock();
}

void	FJMI::printDuration()
{
	double duration = (((double)(_endTime - _startTime)) / CLOCKS_PER_SEC) * 1000000.0;

	std::cout << "Time to process a range of " << sequence_size << " with std::vector : " << duration << " µs" << std::endl;
}

void	FJMI::printBefore()
{
	std::cout << "Before:";
	for (size_t i = 0 ; i < (sequence_size <= 10 ? sequence_size : 5) ; i++)
		std::cout << " " << sequence[i];
	if (sequence_size > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}

void	FJMI::printAfter()
{
	std::cout << "After:";
	for (size_t i = 0 ; i < (sequence_size <= 10 ? sequence_size : 5) ; i++)
		std::cout << " " << sequence[i];
	if (sequence_size > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}