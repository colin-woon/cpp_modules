./PmergeMe 5 3 4 2 1

echo
./PmergeMe 7 6 5 4 3 2 1

echo
./PmergeMe 5 2 7 3 6 1 4

# change -n 3000 to any number for more integers
 ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
