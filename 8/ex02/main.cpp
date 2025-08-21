#include <MutantStack.hpp>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	// Empty stack iteration
// 	MutantStack<int> emptyStack;
// 	std::cout << "Iterating over empty stack:" << std::endl;
// 	for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it)
// 		std::cout << *it << std::endl;

// 	// Single element stack
// 	emptyStack.push(42);
// 	std::cout << "Iterating over single element stack:" << std::endl;
// 	for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it)
// 		std::cout << *it << std::endl;

// 	// Const iteration
// 	const MutantStack<int> constStack = emptyStack;
// 	std::cout << "Const iteration:" << std::endl;
// 	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
// 		std::cout << *it << std::endl;
// 	std::stack<int> s(emptyStack);
// 	return 0;
// }
