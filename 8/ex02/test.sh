make
make list

./list > list.out
./mutantstack > mutantstack.out

diff list.out mutantstack.out

make fclean
rm -rf list.out mutantstack.out
