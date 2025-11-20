#include "PmergeMe.hpp"

PmergeMe::FindByKey::FindByKey(int val) : target(val) {}

bool PmergeMe::FindByKey::operator()(const PairType &p) const
{
	return p.first == target;
}

PmergeMe::PmergeMe() : _vect() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vect = other._vect;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vect = other._vect;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addToVector(PairType p)
{
	_vect.push_back(p);
}

void PmergeMe::printVector() const
{
	vector<PairType>::const_iterator it;

	for (it = _vect.begin(); it != _vect.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}
}
