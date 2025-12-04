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
	-
## ex02
- used Vector & List
- FordJohnson Algorithm
- Explain Jacobsthal Numbers
- Explain comparison counters, and why organizing data doesnt count towards the comparison counter
- Explain how random access differs, memory issues
