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
using std::list;
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

	// ========== VECTOR HANDLER ==========
	class VectorSorter
	{
	private:
		vector<int> _input;
		vector<int> _sorted;

		void getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const vector<int> &referenceSortedMainChain);
		void insertLosersBackwardFromJacobsthal(const vector<int> &initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain, long &winnerPos);
		bool tryInsertOrphanLoser(JacobsthalRecursionState &state, const vector<int> initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain);
		void insertFirstLoser(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs);
		void insertPending(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs, JacobsthalRecursionState &state);
		void makePairs(vector<int> &unsortedMainChain, vector<int> &newMainChain, vector<PairType> &pairs, bool &hasOrphan);
		vector<int> fordJohnsonSortVector(vector<int> &winners);

	public:
		VectorSorter();
		VectorSorter(const VectorSorter &other);
		VectorSorter &operator=(const VectorSorter &other);
		~VectorSorter();

		void add(int val);
		void sort();
		void printPairs(vector<PairType> &input) const;
		// const vector<int> &getResult() const;
		// void printResult() const;
	};

	// ========== LIST HANDLER ==========
	class ListSorter
	{
	private:
		list<int> _input;
		list<int> _sorted;

		// void getInsertIndexFromJacobsthal(JacobsthalRecursionState &state, const vector<int> &referenceSortedMainChain);
		// void insertLosersBackwardFromJacobsthal(const vector<int> &initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain, long &winnerPos);
		// bool tryInsertOrphanLoser(JacobsthalRecursionState &state, const vector<int> initialSortedMainChain, vector<PairType> &pairs, vector<int> &sortedMainChain);
		// void insertFirstLoser(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs);
		// void insertPending(const vector<int> initialSortedMainChain, vector<int> &sortedMainChain, vector<PairType> &pairs, JacobsthalRecursionState &state);
		// void makePairs(vector<int> &unsortedMainChain, vector<int> &newMainChain, vector<PairType> &pairs, bool &hasOrphan);
		// vector<int> fordJohnsonSortVector(vector<int> &winners);

	public:
		ListSorter();
		ListSorter(const ListSorter &other);
		ListSorter &operator=(const ListSorter &other);
		~ListSorter();

		void add(int val);
		void sort();
		// void printPairs(vector<PairType> &input) const;
		void printList() const;
	};

	VectorSorter _vectorSorter;
	ListSorter _listSorter;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void addToVector(int val);
	void sortVector();
	void addToList(int val);
	void sortList();
	void printResults() const;
};

#endif
