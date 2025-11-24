#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <iterator>

using std::advance;
using std::cerr;
using std::cout;
using std::distance;
using std::endl;
using std::iterator_traits;
using std::pair;
using std::vector;

extern int gComparisonCount;

template <class ForwardIterator, class T>
ForwardIterator custom_lower_bound(ForwardIterator first, ForwardIterator last, const T &val)
{
	ForwardIterator it;
	typename iterator_traits<ForwardIterator>::difference_type count, step;

	count = distance(first, last);
	while (count > 0)
	{
		it = first;
		step = count / 2;
		advance(it, step);
		gComparisonCount++;
		if (*it < val)
		{
			// Element is in the upper half
			first = ++it;
			count -= step + 1;
		}
		else
		{
			// Element is either the value or in the lower half
			count = step;
		}
	}
	return first;
}

typedef pair<int, int> PairType;

class PmergeMe
{
private:
	// vector<PairType> _vect;
	vector<int> _inputVect;
	vector<int> _sortedVect;

	// A Functor, making an object behave like a function
	// eg:
	// say the operator() was overloaded to "target + val"
	// FindByKey a(12);
	// int result = a(40);
	// result will be equal to 42
	struct FindByKey
	{
		int target;
		FindByKey(int val);
		bool operator()(const PairType &p) const;
	};

	struct JacobsthalRecursionState
	{
		JacobsthalRecursionState();
		long previousJacobsthalNumber;
		long currentJacobsthalNumber;
		long i;
		bool hasOrphan;
		bool isLastIteration;
	};

	void getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const vector<int> &referenceSortedMainChain);
	void insertPending(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs, JacobsthalRecursionState &state);
	vector<int> fordJohnsonSortVector(vector<int> &winners);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void addToVector(int p);
	void printVector(vector<PairType> &input) const;
	void sortVector();
};

#endif
