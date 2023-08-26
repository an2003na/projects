#include "bitset.h"


int main ()
{
	Bitset b(20);
	b.set (4);
	b.reset(5);
	std::cout << b.get_size();
	return 0;
}
