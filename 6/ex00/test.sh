make

echo "Char Tests"
./convert "'"
echo
./convert "'7'"
echo
./convert a
echo
./convert z
echo
./convert '#'
echo
./convert "$(printf "\007")"
echo

echo "Int Tests"
make fclean
