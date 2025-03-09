# abc@==@123

# abc==123
./replace test1.txt '@' ""

# abc@@123
./replace test1.txt '=' ""

# @==@123
./replace test1.txt 'abc' ""

# abc@==@
./replace test1.txt '123' ""

# 123@==@123
./replace test1.txt 'abc' "123"

# abc@asdasd@123
./replace test1.txt '=' "asd"

# 1234@==@123
./replace test1.txt 'abc' "1234"
