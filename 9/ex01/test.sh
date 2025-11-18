echo "Subject tests"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

./RPN "7 7 * 7 -"

./RPN "1 2 * 2 / 2 * 2 4 - +"
echo

echo "Divide zero"
./RPN "1 0 /"
echo

echo "Negative result"
./RPN "1 9 -"
echo

echo "Extra operator"
./RPN "1 9 - +"
echo

echo "Incorrect formats"
echo "Parentheses ()"
./RPN "(1 + 1)"
echo

echo "Decimal"
./RPN "1.1 1 +"
echo

echo "Infix"
./RPN "1 + 1"
echo

echo "Regular Polish Notation"
./RPN "+ 1 1"
echo

echo
