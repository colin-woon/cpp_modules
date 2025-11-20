#include "PmergeMe.hpp"

PmergeMe::FindByKey::FindByKey(int val) : target(val) {}

bool PmergeMe::FindByKey::operator()(const PairType &p) const
{
	return p.first == target;
}

PmergeMe::PmergeMe() : _inputVect() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_inputVect = other._inputVect;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_inputVect = other._inputVect;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addToVector(int p)
{
	_inputVect.push_back(p);
}

void PmergeMe::printVector(vector<PairType> &input) const
{
	vector<PairType>::const_iterator it;

	for (it = input.begin(); it != input.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}
}

static void printSortedVector(vector<int> &input)
{
	vector<int>::const_iterator it;

	cout << "Sorted" << endl;
	for (it = input.begin(); it != input.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "end" << endl;
}

// Helper to check if a number is a power of 2 using bitwise magic
// (x & (x - 1)) == 0 is the classic hack for this.
bool isPowerOfTwo(long long x)
{
	return x > 0 && (x & (x - 1)) == 0;
}

long long getNextJacobSthal(long long currentNum)
{
	if (currentNum == 0 || currentNum == 1)
		return 1;

	// LOGIC CHECK:
	// If (3 * current + 1) is a power of 2, the index 'n' was EVEN.
	// If index is even, the formula for next is: 2 * J + 1
	if (isPowerOfTwo(3 * currentNum + 1))
	{
		return (2 * currentNum) + 1;
	}
	// Otherwise index was ODD, formula is: 2 * J - 1
	else
	{
		return (2 * currentNum) - 1;
	}
}

vector<int> PmergeMe::fordJohnsonSortVector(vector<int> &winners)
{
	if (winners.size() == 1)
		return winners;

	vector<int>::iterator it;
	vector<PairType> groups;
	vector<int> mainChain;

	for (it = winners.begin(); it < winners.end() - 1; it += 2)
	{
		groups.push_back(std::make_pair(*it, *(it + 1)));
		PairType &pairIt = groups.back();
		if (pairIt.first < pairIt.second)
			std::swap(pairIt.first, pairIt.second);
		mainChain.push_back(pairIt.first);
	}
	if (it == winners.end() - 1)
		groups.push_back(std::make_pair(-1, *it));

	vector<int> sortedWinners = fordJohnsonSortVector(mainChain);
	if (sortedWinners.size() == 1)
	{
		it = _sortedVect.begin();
		_sortedVect.insert(it, sortedWinners[0]);
	}
	else
	{
		int lastNum = 1;
		int countFrom = getNextJacobSthal(lastNum);
	}
	printVector(groups);
	printSortedVector(sortedWinners);
	return sortedWinners;
}

void PmergeMe::sortVector()
{
	vector<int> temp = fordJohnsonSortVector(_inputVect);
	printSortedVector(_sortedVect);
}
