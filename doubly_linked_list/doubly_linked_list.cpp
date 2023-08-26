#include "doubly_linked_list.h"

int main()
{
	try {
		DoublyLinkedList<int> list;
		list.insert(0, 5);
		list.push_back(13);
		list.push_front(20);
		list.push_back(56);
		list.push_back(26);
		list.push_back(9);
		list.push_back(35);
		list.print_list();
		list.print_reverse();
		list.pop_back();
		list.pop_front();
		list.remove(2);
		list.print_list();
		list.print_reverse();
		std::cout << list.get(1);
	} catch (const std::invalid_argument& exp) {
		std::cout << exp.what();
	}
	return 0;
}
