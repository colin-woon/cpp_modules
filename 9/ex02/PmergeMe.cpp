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
void PmergeMe::VectorSorter::printVector(vector<int> &input) const
{
	vector<int>::const_iterator it;

	for (it = input.begin(); it != input.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
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

void PmergeMe::addToVector(int val)
{
	_vectorSorter.add(val);
}

void PmergeMe::sortVector()
{
	_vectorSorter.sort();
}
void PmergeMe::addToList(int val)
{
	_listSorter.add(val);
}

void PmergeMe::sortList()
{
	_listSorter.sort();
}

void PmergeMe::printResults()
{
	cout << "--VECTOR--" << endl;
	cout << "Before:	";
	_vectorSorter.printVector(_vectorSorter._input);

	cout << "After:	";
	_vectorSorter.printVector(_vectorSorter._sorted);

	cout << "--LIST--" << endl;
	cout << "Before:	";
	_listSorter.printList(_listSorter._input);

	cout << "After:	";
	_listSorter.printList(_listSorter._sorted);

	cout << "Comparisons in std::vector: " << _vectorSorter.comparisons << endl;
	cout << "Comparisons in std::list: " << _listSorter.comparisons << endl;
	if (!isSorted(_vectorSorter._sorted.begin(), _vectorSorter._sorted.end()))
		std::cout << "Vector is NOT sorted." << std::endl;
	if (!isSorted(_listSorter._sorted.begin(), _listSorter._sorted.end()))
		std::cout << "List is NOT sorted." << std::endl;

	cout
		<< "Time to process a range of " << _vectorSorter._input.size() << " with std::vector: "
		<< std::fixed << std::setprecision(3)
		<< _vectorSorter.timeTakenMS << " miliseconds" << endl;

	cout
		<< "Time to process a range of " << _listSorter._input.size() << " with std::list: "
		<< std::fixed << std::setprecision(3)
		<< _listSorter.timeTakenMS << " miliseconds" << endl;
}

// VectorSorter Class Implementation
PmergeMe::VectorSorter::VectorSorter() : _input(), _sorted() {}

PmergeMe::VectorSorter::VectorSorter(const VectorSorter &other)
{
	this->_input = other._input;
	this->_sorted = other._sorted;
}

PmergeMe::VectorSorter &PmergeMe::VectorSorter::operator=(const VectorSorter &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_sorted = other._sorted;
	}
	return *this;
}

PmergeMe::VectorSorter::~VectorSorter() {}

void PmergeMe::VectorSorter::add(int val)
{
	_input.push_back(val);
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
	clock_t startTime = clock();
	_sorted = fordJohnsonSortVector(_input);
	clock_t endTime = clock();
	this->timeTakenMS = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
	this->comparisons = gComparisonCount;
}

// ListSorter Class Implementation
PmergeMe::ListSorter::ListSorter() : _input(), _sorted() {}

PmergeMe::ListSorter::ListSorter(const ListSorter &other) : _input(other._input), _sorted(other._sorted) {}

PmergeMe::ListSorter &PmergeMe::ListSorter::operator=(const ListSorter &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_sorted = other._sorted;
	}
	return *this;
}

PmergeMe::ListSorter::~ListSorter() {}

void PmergeMe::ListSorter::add(int val)
{
	this->_input.push_back(val);
}

void PmergeMe::ListSorter::printPairs(list<PairType> &input) const
{
	list<PairType>::const_iterator it;

	for (it = input.begin(); it != input.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}
}

void PmergeMe::ListSorter::printList(list<int> aList) const
{
	list<int>::const_iterator it;

	for (it = aList.begin(); it != aList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void PmergeMe::ListSorter::makePairs(list<int> &unsortedMainChain, list<int> &newMainChain, list<PairType> &pairs, bool &hasOrphan)
{
	list<int>::iterator it = unsortedMainChain.begin();

	while (it != unsortedMainChain.end())
	{
		int first = *it;
		it++;

		if (it == unsortedMainChain.end())
		{
			pairs.push_back(std::make_pair(-1, first));
			hasOrphan = true;
			break;
		}

		int second = *it;
		pairs.push_back(std::make_pair(first, second));
		PairType &pairIt = pairs.back();
		gComparisonCount++;
		if (pairIt.first < pairIt.second)
			std::swap(pairIt.first, pairIt.second);
		newMainChain.push_back(pairIt.first);
		it++;
	}
}

void PmergeMe::ListSorter::getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const list<int> &initialSortedMainChain)
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

void PmergeMe::ListSorter::insertFirstLoser(const list<int> initialSortedMainChain, list<int> &sortedMainChain, list<PairType> &pairs)
{
	list<int>::iterator it = sortedMainChain.begin();
	list<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChain.front()));
	sortedMainChain.insert(it, pairIt->second);
}

bool PmergeMe::ListSorter::tryInsertOrphanLoser(JacobsthalRecursionState &state, const list<int> initialSortedMainChain, list<PairType> &pairs, list<int> &sortedMainChain)
{
	if (!state.hasOrphan || state.i < (long)initialSortedMainChain.size())
		return false;

	list<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(-1));
	list<int>::iterator insertPosition = custom_lower_bound(sortedMainChain.begin(), sortedMainChain.end(), pairIt->second);
	sortedMainChain.insert(insertPosition, pairIt->second);
	state.i = initialSortedMainChain.size() - 1;
	return true;
}

void PmergeMe::ListSorter::insertLosersBackwardFromJacobsthal(const list<int> &initialSortedMainChain, list<PairType> &pairs, list<int> &sortedMainChain, long &winnerPos)
{
	long &i = winnerPos;

	std::list<int>::const_iterator it = initialSortedMainChain.begin();
	std::advance(it, i);
	int initialSortedMainChainValue = *it;
	list<PairType>::iterator pairIt = std::find_if(pairs.begin(), pairs.end(), FindByKey(initialSortedMainChainValue));
	list<int>::iterator endRange = std::lower_bound(sortedMainChain.begin(), sortedMainChain.end(), pairIt->first);
	list<int>::iterator insertPosition = custom_lower_bound(sortedMainChain.begin(), endRange, pairIt->second);
	sortedMainChain.insert(insertPosition, pairIt->second);
}

void PmergeMe::ListSorter::insertPending(const list<int> initialSortedMainChain, list<int> &sortedMainChain, list<PairType> &pairs, JacobsthalRecursionState &state)
{
	long &i = state.i;
	list<int>::iterator it;

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

list<int> PmergeMe::ListSorter::fordJohnsonSortList(list<int> &unsortedMainChain)
{
	if (unsortedMainChain.size() == 1)
		return unsortedMainChain;

	list<int>::iterator it;
	list<PairType> pairs;
	list<int> newMainChain;
	JacobsthalRecursionState state;

	makePairs(unsortedMainChain, newMainChain, pairs, state.hasOrphan);

	list<int> sortedMainChain = fordJohnsonSortList(newMainChain);
	const list<int> initialSortedMainChain = sortedMainChain;

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
	// cout << "Printing pairs" << endl;
	// printPairs(pairs);
	// printList(sortedMainChain);
	return sortedMainChain;
}

void PmergeMe::ListSorter::sort()
{
	clock_t startTime = clock();
	_sorted = fordJohnsonSortList(_input);
	clock_t endTime = clock();
	this->timeTakenMS = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
	this->comparisons = gComparisonCount;
}
