make

# echo "-------CHAR TEST-------"
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
# echo "-------END-------"

echo "-------INT TEST-------"
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
echo "-------END-------"

echo "-------DOUBLE TESTS-------"
./convert +2147483648.0
echo
./convert -2147483649.0
echo
./convert 66.
echo
./convert .66
echo
./convert .6.6
echo
./convert 43.66
echo
./convert 4a3.6a6
echo "-------END-------"

echo "-------FLOAT TESTS-------"
./convert +2147483648.0f
echo
./convert -2147483649.0f
echo
./convert 66.f
echo
./convert .66f
echo
./convert .6.6f
echo
./convert 43.66f
echo
./convert 4a3.6a6f
echo "-------END-------"

make fclean
