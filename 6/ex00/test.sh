make

# echo "Char Tests"
# ./convert "'"
# echo
# ./convert "'7'"
# echo
# ./convert a
# echo
# ./convert z
# echo
# ./convert '#'
# echo
# ./convert "$(printf "\007")"
# echo

echo "Int Tests"
./convert -2147483648
echo
./convert 2147483647
echo
./convert 2147483648
echo
./convert -2147483649
echo
./convert -66
echo
./convert 66
echo
./convert 9999999999999999999999

make fclean
