#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

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
