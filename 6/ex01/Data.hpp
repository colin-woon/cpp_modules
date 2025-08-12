#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
	char _c;
	int _num;
	float _numF;

public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};

#endif
