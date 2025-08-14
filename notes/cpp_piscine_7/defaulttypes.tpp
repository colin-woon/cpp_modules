#include <iostream>
#include <iomanip>

// Fallback to default type if no type specified
template <typename T = float>
class Vertex
{

private:
	T const _x;
	T const _y;
	T const _z;

	Vertex();

public:
	Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}
	~Vertex(void) {}

	T const &getX(void) const { return this->_x; }
	T const &getY(void) const { return this->_y; }
	T const &getZ(void) const { return this->_z; }
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Vertex<T> const &v)
{
	std::cout.precision(1);
	o << setiosflags(std::ios::fixed);
	o << "Vertex(";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ() << " )";

	return o;
}
