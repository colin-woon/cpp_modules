#include "PmergeMe.hpp"

int gComparisonCount = 0;

PmergeMe::JacobsthalRecursionState::JacobsthalRecursionState() : previousJacobsthalNumber(0), currentJacobsthalNumber(0), i(0), hasOrphan(false), isLastIteration(false) {}

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

long getNextJacobsthal(long currentNum)
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

void makePairs(vector<int> &unsortedMainChain, vector<int> &newMainChain, vector<PairType> &pairs, bool &hasOrphan)
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

void PmergeMe::getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const vector<int> &initialSortedMainChain)
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

void PmergeMe::insertPending(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs, JacobsthalRecursionState &state)
{
	long &i = state.i;
	vector<int>::iterator it;

	while (i >= 0 && i > state.previousJacobsthalNumber - 1)
	{
		if (i == 0)
		{
			it = sortedMainChain.begin();
			vector<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChain[0]));
			sortedMainChain.insert(it, pairIt->second);
		}
		else
		{
			vector<PairType>::iterator pairIt;
			vector<int>::iterator insertPosition;
			vector<int>::iterator endRange;

			if (state.hasOrphan && i >= (long)initialSortedMainChain.size())
			{
				pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(-1));
				endRange = sortedMainChain.end();
				insertPosition = custom_lower_bound(sortedMainChain.begin(), endRange, pairIt->second);
				sortedMainChain.insert(insertPosition, pairIt->second);
				i = initialSortedMainChain.size() - 1;
				continue;
			}
			else
			{
				pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChain[i]));
				endRange = std::lower_bound(sortedMainChain.begin(), sortedMainChain.end(), pairIt->first);
				insertPosition = custom_lower_bound(sortedMainChain.begin(), endRange, pairIt->second);
				sortedMainChain.insert(insertPosition, pairIt->second);
			}
		}
		i--;
	}
}

vector<int> PmergeMe::fordJohnsonSortVector(vector<int> &unsortedMainChain)
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
	_sortedVect = sortedMainChain;
	printVector(pairs);
	printSortedVector(sortedMainChain);
	return sortedMainChain;
}

void PmergeMe::sortVector()
{
	vector<int> temp = fordJohnsonSortVector(_inputVect);
	cout << "done" << endl;
	cout << gComparisonCount << endl;
	printSortedVector(_sortedVect);
}
