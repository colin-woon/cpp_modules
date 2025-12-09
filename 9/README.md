# C++ Containers
- the containers can only be used once per exercise, will be forbidden in the next

## ex00
- used Map
- program uses a .csv file like a pseudo database storing Bitcoin prices
- program accepts a file as argument (eg: ./btc input.txt)
- file must be formatted as follows:
```sh
date | value
YYYY-MM-DD | value
```
- constraints and limitations:
	- multiple inputs
	- invalid values (only 0-1000 allowed, either float or positive integer)
	- invalid dates
	- invalid file extensions (its hardcoded as data.csv & input.txt)
### DECISIONS
  - Initially thought of using generic extractFile function to extract both input.txt and data.csv, but realized there was no need to optimize it like that, as output of the program seems to want the input.txt to be looped line by line to process
  - Used std::string to represent the delimiter " | ", so easily comparable and changed if needed, dont have to worry about whitespace
  - Using std::tm to check for date std::mktime validates it
  - Using std::lower_bound to find the closest date to the input date (closest date > input date), because of how it works, inputDate that is earlier than all dates will throw error, while inputDate latest than all dates will just take the latest date.
  - only the InvalidInputFormatException has a constructor because it needs to take in the line bad date as reference


## ex01
- used Stack (deque)
- Infix Notation 3 + 4 is built for humans, but it's terrible for computers, because of PEMDAS and parenthesis (eg: 5 + 2 x 3 + (2 + 2), which one first?)
- Polish Notation & Reverse Polish Notation - removes the need for parenthesis, makes it simple
  - **Reverse** (low-level execution and calculators) (**Postfix**)
    - 5 2 3 x + represents 5 + (2 x 3)
    - 5 2 x 3 + represents 5 x 2 + 3
    - much simpler as operands are waiting on stack, when operator comes in, pop operand and calculate
  - **Normal** (high-level languagges in functional programming like LISP) (**Prefix**)
	- + 3 x 4 5 represents 3 + (4 x 5)
	- x + 3 4 5 represents (3 + 4) x 5
	- more memory load because when operator comes in, still needs to wait for operands then only execute, once operands are ready, needs to remember what operator was waiting (need complex recursion, might cause stack overflow)
- handled zero division
- prevented multiple digits numbers, only 0-9 allowed, no >=10

## ex02
- FordJohnson Algorithm (Merge-Insertion Sort)
- Jacobsthal Numbers (Formula: 2(prevNumber) + currentNumber - 1, 3, 5, 11, 21)
- A recursion of grouping elements into pairs and sorting them, then taking the winners and continue, afterwards insert the losers into the sorted winners according to jacobsthal sequence backwards, we use the jacobsthal number as index to refer to the initial sorted winners to find their loser pair to be inserted. (eg: 1, 3, 2, 5, 4, 11, 10, 9 ,8 , 7, 6)
- If an orphan is found, it will be inserted based on jacobsthal sequence first also, typically when the losers container is larger than the winners container in our implementation because the orphan is paired with -1 as a default. (first->-1, second->\<ORPHAN\>)
- the minimum comparisons refer to the worst case scenario, whats the maximum amount of comparisons required, so you might take a few tries to find the worst case scenario for the same set of numbers
- actual implementation uses a Directed Graph, where the ordering relations is known, but we are only using vectors and lists so we cant really replicate it without implementation overhead
- Vectors vs List
- O(1) random access for vector if you have the index, O(n) for list as its pointers and not contiguous memory
- slower insertion in the middle of a vector, but faster for list

### DECISIONS
- used Vector & List
- used a global variable to store the comparison count to compare with actual fordJohnson based [on pg 186(198/792) of The Art of Computer Programming](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf) (only related to sorting data itself, organizing does not count)
- using clock to calculate time instead of time_t because clock calculates CPU time in microseconds, while time_t is more for real world time, it includes waiting time.
