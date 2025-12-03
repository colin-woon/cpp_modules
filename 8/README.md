

# STL (Standard Template Library)
- containers
- algorithms
- iterators

## ex00
- easyfind
- just a template that accepts any non-associative container to find a specific integer in it using the std::find algorithm

## ex01
- Span
- a custom container class that define the range or difference between numbers stored in a collection, subject to a maximum capacity
```c++
Span(unsigned int size)
- //define max capacity

addNumber()
- //add number subject to max capacity, throw exception if exceed
shortestSpan()
- // find the minimum difference between elements (eg: 1, 5, 7 1-5 = 4, 5-7 = 2, 2 is the shortest span, making it sorted will be much easier)

longestSpan()
- // find the maximum difference between elements (just subtract the min and max)

fillNumbers(iterator from, iterator to)
- // fill the container with a range of numbers from an existing container, since iterators are pointers, just dereferencing them can give the value
```

##ex02
- MutantStack
- making the stack iterable.
- Learn about container adaptors, theyre built on top of an existing container, in this case, deque, but with a specific set of operations, eg: stack only allows push and pop, but deque allows more operations;
