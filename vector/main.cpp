#include "vector.h"

int main() {
	try {
		Vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.pop_front();
		v.pop_back();
		v.insert(1, 89);
		v.print();
		v.clear();
		v.push_front(56);
		v.print();
		Vector<int> v2(2);
		v2.insert(0, 65);
		v2.insert(1, 63);
		v2.insert(2, 60);
		v2.print();
	}
	catch (const std::invalid_argument& exp) {
		std::cout << exp.what() << std::endl;
	}
	return 0;
}
