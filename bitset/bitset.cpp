#include "bitset.h"

Bitset::Bitset(int n) {
	if (n < 0) { return; }
	if (n % (8 * sizeof(unsigned long)) == 0) {
		size = n / (8 * sizeof(unsigned long));
	} else {
		size = n / (8 * sizeof(unsigned long)) + 1;
	}
	arr = new unsigned long[size];
	for (int i = 0; i < size; ++i) {
		arr [i] = 0;
	}
}

//0->1
void Bitset::set(int n) {
	if (n < 0) { return; }
	int s = 8 * sizeof(unsigned long);
	size_t index {};
	while (n >= s) {
		n = n - s;
		index++;
	}
	unsigned long k = 1;
	for (int i = 0; i < n; ++i) { k = k * 2; }
	arr[index] = arr[index] | k;
}

//1->0
void Bitset::reset(int n) {
	if (n < 0) { return; }
	set(n);
	int s = 8 * sizeof(unsigned long);
	size_t index {};
	while (n >= s) {
		n = n - s;
		index++;
	}
	unsigned long k = 1;
	for (int i = 0; i < n; ++i) { k = k * 2; }
	arr[index] = arr[index] - k;
}

