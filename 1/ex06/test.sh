make

echo
./harlFilter

echo "default switch"
./harlFilter ""
echo
./harlFilter "Hello"
echo

echo "switches accoding to the log level"
./harlFilter "DEBUG"
echo
./harlFilter "INFO"
echo
./harlFilter "WARNING"
echo
./harlFilter "ERROR"

make fclean
