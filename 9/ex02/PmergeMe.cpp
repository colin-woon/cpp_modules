#include "PmergeMe.hpp"

int gComparisonCount = 0;

// Structs
PmergeMe::JacobsthalRecursionState::JacobsthalRecursionState() : previousJacobsthalNumber(0), currentJacobsthalNumber(0), i(0), hasOrphan(false), isLastIteration(false) {}

PmergeMe::FindByKey::FindByKey(int val) : target(val) {}

bool PmergeMe::FindByKey::operator()(const PairType &p) const
{
	return p.first == target;
}

// Main Class Implementation
PmergeMe::PmergeMe() : _vectorSorter() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vectorSorter = other._vectorSorter;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vectorSorter = other._vectorSorter;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// Helper Functions
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

static long getNextJacobsthal(long currentNum)
{
	static long lastNum = 1;
	if (currentNum == 0)
	{
		lastNum = 1;
		return 1;
	}
	else if (currentNum == 1)
	{
		lastNum = 1;
		return 3;
	}

	lastNum = 2 * lastNum + currentNum;

	return (lastNum);
}

void PmergeMe::VectorSorter::add(int val)
{
	_input.push_back(val);
}

void PmergeMe::addToVector(int val)
{
	_vectorSorter.add(val);
}

void PmergeMe::VectorSorter::printPairs(vector<PairType> &input) const
{
	vector<PairType>::const_iterator it;

	for (it = input.begin(); it != input.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}
}

void PmergeMe::VectorSorter::makePairs(vector<int> &unsortedMainChain, vector<int> &newMainChain, vector<PairType> &pairs, bool &hasOrphan)
{
	vector<int>::iterator it;

	for (it = unsortedMainChain.begin(); it < unsortedMainChain.end() - 1; it += 2)
	{
		pairs.push_back(std::make_pair(*it, *(it + 1)));
		PairType &pairIt = pairs.back();
		gComparisonCount++;
		if (pairIt.first < pairIt.second)
			std::swap(pairIt.first, pairIt.second);
		newMainChain.push_back(pairIt.first);
	}
	if (it == unsortedMainChain.end() - 1)
	{
		pairs.push_back(std::make_pair(-1, *it));
		hasOrphan = true;
	}
}

void PmergeMe::VectorSorter::getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const vector<int> &initialSortedMainChain)
{
	bool &isLastIteration = state.isLastIteration;
	long &previousJacobsthalNumber = state.previousJacobsthalNumber;
	long &i = state.i;
	long &currentJacobsthalNumber = state.currentJacobsthalNumber;

	isLastIteration = false;
	currentJacobsthalNumber = getNextJacobsthal(previousJacobsthalNumber);
	if (currentJacobsthalNumber > (long)initialSortedMainChain.size())
	{
		if (!state.hasOrphan)
			i = initialSortedMainChain.size() - 1;
		else
			i = currentJacobsthalNumber - 1;
		isLastIteration = true;
	}
	else
		i = currentJacobsthalNumber - 1;
}

void PmergeMe::VectorSorter::insertFirstLoser(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs)
{
	vector<int>::iterator it = sortedMainChain.begin();
	vector<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChain[0]));
	sortedMainChain.insert(it, pairIt->second);
}

bool PmergeMe::VectorSorter::tryInsertOrphanLoser(JacobsthalRecursionState &state, const vector<int> initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain)
{
	if (!state.hasOrphan || state.i < (long)initialSortedMainChain.size())
		return false;

	vector<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(-1));
	vector<int>::iterator insertPosition = custom_lower_bound(sortedMainChain.begin(), sortedMainChain.end(), pairIt->second);
	sortedMainChain.insert(insertPosition, pairIt->second);
	state.i = initialSortedMainChain.size() - 1;
	return true;
}

void PmergeMe::VectorSorter::insertLosersBackwardFromJacobsthal(const vector<int> &initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain, long &winnerPos)
{
	long &i = winnerPos;

	vector<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChain[i]));
	vector<int>::iterator endRange = std::lower_bound(sortedMainChain.begin(), sortedMainChain.end(), pairIt->first);
	vector<int>::iterator insertPosition = custom_lower_bound(sortedMainChain.begin(), endRange, pairIt->second);
	sortedMainChain.insert(insertPosition, pairIt->second);
}

void PmergeMe::VectorSorter::insertPending(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs, JacobsthalRecursionState &state)
{
	long &i = state.i;
	vector<int>::iterator it;

	while (i >= 0 && i > state.previousJacobsthalNumber - 1)
	{
		if (i == 0)
			insertFirstLoser(initialSortedMainChain, sortedMainChain, pairs);
		else if (tryInsertOrphanLoser(state, initialSortedMainChain, pairs, sortedMainChain))
			continue;
		else
			insertLosersBackwardFromJacobsthal(initialSortedMainChain, pairs, sortedMainChain, i);
		i--;
	}
}

vector<int> PmergeMe::VectorSorter::fordJohnsonSortVector(vector<int> &unsortedMainChain)
{
	if (unsortedMainChain.size() == 1)
		return unsortedMainChain;

	vector<int>::iterator it;
	vector<PairType> pairs;
	vector<int> newMainChain;
	JacobsthalRecursionState state;

	makePairs(unsortedMainChain, newMainChain, pairs, state.hasOrphan);

	vector<int> sortedMainChain = fordJohnsonSortVector(newMainChain);
	const vector<int> initialSortedMainChain = sortedMainChain;

	long &previousJacobsthalNumber = state.previousJacobsthalNumber;
	long &i = state.i;

	while (true)
	{
		getInsertIndexFromJacobsthal(state, initialSortedMainChain);
		insertPending(initialSortedMainChain, sortedMainChain, pairs, state);
		if (state.isLastIteration)
			break;
		state.previousJacobsthalNumber = state.currentJacobsthalNumber;
	}
	_sorted = sortedMainChain;
	// printPairs(pairs);
	// printSortedVector(sortedMainChain);
	return sortedMainChain;
}

void PmergeMe::VectorSorter::sort()
{
	_sorted = fordJohnsonSortVector(_input);
	cout << "done" << endl;
	cout << gComparisonCount << endl;
	// printSortedVector(_sorted);
}

void PmergeMe::sortVector()
{
	_vectorSorter.sort();
}
