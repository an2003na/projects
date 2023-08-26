#ifndef BITSET_H
#define BITSET_H

#include <iostream>

class Bitset
{
public:
	explicit Bitset(int);
	void set(int);
	void reset(int);
	size_t get_size() { return size; }
	~Bitset() {
		delete [] arr;
		arr = nullptr;
	}

private:
	unsigned long* arr;
	size_t size;
};




#endif
