#include "PmergeMe.hpp"

int gComparisonCount = 0;

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

vector<int> PmergeMe::fordJohnsonSortVector(vector<int> &winners)
{
	if (winners.size() == 1)
		return winners;

	vector<int>::iterator it;
	vector<PairType> groups;
	vector<int> mainChain;
	bool hasOrphan = false;

	for (it = winners.begin(); it < winners.end() - 1; it += 2)
	{
		groups.push_back(std::make_pair(*it, *(it + 1)));
		PairType &pairIt = groups.back();
		gComparisonCount++;
		if (pairIt.first < pairIt.second)
			std::swap(pairIt.first, pairIt.second);
		mainChain.push_back(pairIt.first);
	}
	if (it == winners.end() - 1)
	{
		groups.push_back(std::make_pair(-1, *it));
		hasOrphan = true;
	}

	vector<int> sortedWinners = fordJohnsonSortVector(mainChain);
	const vector<int> referenceSortedWinners = sortedWinners;

	long totalPendingLosers = groups.size();
	long previousJacobsthalNumber = 0;
	for (long i = 0; i < totalPendingLosers;)
	{
		bool isLastIteration = false;
		int currentJacobsthalNumber = getNextJacobsthal(previousJacobsthalNumber);
		if (currentJacobsthalNumber > referenceSortedWinners.size())
		{
			if (!hasOrphan)
				i = referenceSortedWinners.size() - 1;
			else
				i = currentJacobsthalNumber - 1;
			isLastIteration = true;
		}
		else
			i = currentJacobsthalNumber - 1;
		while (i >= 0 && i > previousJacobsthalNumber - 1)
		{
			if (i == 0)
			{
				it = sortedWinners.begin();
				vector<PairType>::iterator pairIt = std::find_if(groups.begin(), groups.end(), FindByKey(referenceSortedWinners[0]));
				sortedWinners.insert(it, pairIt->second);
			}
			else
			{
				vector<PairType>::iterator pairIt;
				vector<int>::iterator insertPosition;
				vector<int>::iterator endRange;

				if (hasOrphan && i >= referenceSortedWinners.size())
				{
					pairIt = std::find_if(groups.begin(), groups.end(), FindByKey(-1));
					endRange = sortedWinners.end();
					insertPosition = custom_lower_bound(sortedWinners.begin(), endRange, pairIt->second);
					sortedWinners.insert(insertPosition, pairIt->second);
					i = referenceSortedWinners.size() - 1;
					continue;
				}
				else
				{
					pairIt = std::find_if(groups.begin(), groups.end(), FindByKey(referenceSortedWinners[i]));
					endRange = std::lower_bound(sortedWinners.begin(), sortedWinners.end(), pairIt->first);
					insertPosition = custom_lower_bound(sortedWinners.begin(), endRange, pairIt->second);
					sortedWinners.insert(insertPosition, pairIt->second);
				}
			}
			i--;
		}
		if (isLastIteration)
			break;
		previousJacobsthalNumber = currentJacobsthalNumber;
	}
	_sortedVect = sortedWinners;
	printVector(groups);
	printSortedVector(sortedWinners);
	return sortedWinners;
}

void PmergeMe::sortVector()
{
	vector<int> temp = fordJohnsonSortVector(_inputVect);
	cout << "done" << endl;
	cout << gComparisonCount << endl;
	printSortedVector(_sortedVect);
}
