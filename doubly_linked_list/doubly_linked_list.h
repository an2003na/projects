#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};
	void push_front(const T&);
	void push_back(const T&);
	void insert(int, const T&);
	void pop_front();
	void pop_back();
	void remove(int);
	T get(int index) const;
	void print_list() const;
	void print_reverse() const;
	size_t length() const { return size; }
	~DoublyLinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	};

private:
	struct Node
	{
		T value;
		Node* prev;
		Node* next;
		explicit Node(const T& value) : value(value), prev(nullptr), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	size_t size;
};



/* Adds a new node with the given value at the beginning of the list.
 */
template <typename T>
void DoublyLinkedList<T>::push_front(const T& val) {
	Node* temp = new Node(val);
	temp->next = head;
	if (head) {
		head->prev = temp;
	}
	head = temp;
	if (!tail) { //if list is empty
		tail = temp;
	}
	size++;
}



/* Adds a new node with the given value at the end of the list.
 */
template <typename T>
void DoublyLinkedList<T>::push_back(const T& val) {
	Node* temp = new Node(val);
	temp->prev = tail;
	if (tail) {
		tail->next = temp;
	}
	tail = temp;
	if (!head) { //if list is empty
		head = temp; 
	}
	size++;
}



/* Inserts a new node with the given value at the specified index.
 */
template <typename T>
void DoublyLinkedList<T>::insert(int index, const T& val) {
	if (size < index) {
		throw std::invalid_argument {"Index is out of range.\n"};
	} else if (index < 0) {
		throw std::invalid_argument {"Index must be a positive integer. \n"};
	}
	if (index == 0) {
		push_front(val);
	} else if (index == size) {
		push_back(val);
	} else {
		Node* temp = new Node(val);
		Node* current = head;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		temp->next = current;
		temp->prev = current->prev;
		current->prev->next = temp;
		current->prev = temp;
		size++;
	}
}



/* Prints the contents of the list from head to tail. 
 */
template <typename T>
void DoublyLinkedList<T>::print_list() const {
	if (head != nullptr) {
		Node* current = head;
		std::cout << current->value;
		current = current->next;
		while (current != nullptr) {
			std::cout << "->" << current->value;
			current = current->next;
		}
		std::cout << std::endl;
	}
}



/* Prints the contents of the list from tail to head.
 */
template <typename T>
void DoublyLinkedList<T>::print_reverse() const {
	if (tail != nullptr) {
		Node* current = tail;
		std::cout << current->value;
		current = current->prev;
		while (current != nullptr) {
			std::cout << "->" << current->value;
			current = current->prev;
		}
		std::cout << std::endl;
	}
}



/* Returns the value of the node at the specified index.
 */
template <typename T>
T DoublyLinkedList<T>::get(int index) const {
	if (size <= index) {
		throw std::invalid_argument {"Index is out of range.\n"};
	} else if (index < 0) {
		throw std::invalid_argument {"Index must be a positive integer. \n"};
	}
	if (index == size - 1) { return head->value; }
	if (index == 0) { return tail->value;}
	Node* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->value;
}



/* Removes the node from the beginning of the list.
 */
template <typename T>
void DoublyLinkedList<T>::pop_front() {
	if (head == nullptr) {
		throw std::invalid_argument {"List is empty!\n"};
	}
	Node* current = head;
	head = current->next;
	if (head) { //if list is not empty
		head->prev = nullptr;
	}
	delete current;
	size--;
}



/* Removes the node from the end of the list.
 */
template <typename T>
void DoublyLinkedList<T>::pop_back() {
	if (tail == nullptr) {
		throw std::invalid_argument {"List is empty!\n"};
	}
	Node* current = tail;
	tail = current->prev;
	if (tail) { //if list is not empty
		tail->next = nullptr;
	}
	delete current;
	size--;
}



/* Removes the node at the specified index.
 */
template <typename T>
void DoublyLinkedList<T>::remove(int index) {
	if (size <= index) {
		throw std::invalid_argument {"Index is out of range.\n"};
	} else if (index < 0) {
		throw std::invalid_argument {"Index must be a positive integer. \n"};
	} else if (size == 0) {
		throw std::invalid_argument {"List is empty!\n"};
	}
	if (index == size - 1) {
		pop_back();
	} else if (index == 0) {
		pop_front();
	} else {
		Node* current = head;
		for (int i = 0; i < index; ++i) {
			current = current->next;
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		size--;
	}
}


#endif

