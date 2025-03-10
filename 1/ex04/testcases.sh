# abc@==@123

# abc==123
echo './replace test1.txt '@' ""'
echo 'abc==123'
./replace test1.txt '@' ""

# abc@@123
echo './replace test1.txt '=' ""'
echo 'abc@@123'
./replace test1.txt '=' ""

# @==@123
echo './replace test1.txt 'abc' ""'
echo '@==@123'
./replace test1.txt 'abc' ""

# abc@==@
echo './replace test1.txt '123' ""'
echo 'abc@==@'
./replace test1.txt '123' ""

# 123@==@123
echo './replace test1.txt 'abc' "123"'
echo '123@==@123'
./replace test1.txt 'abc' "123"

# abc@asdasd@123
echo './replace test1.txt '=' "asd"'
echo 'abc@asdasd@123'
./replace test1.txt '=' "asd"

# 1234@==@123
echo './replace test1.txt 'abc' "1234"'
echo '1234@==@123'
./replace test1.txt 'abc' "1234"

# 12@==@123
echo './replace test1.txt 'abc' "12"'
echo '12@==@123'
./replace test1.txt 'abc' "12"
