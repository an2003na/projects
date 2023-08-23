#include "string.h"

//ctor with parameters
String::String(const char* str) : size(0), capacity(16) {
	string.on_heap = nullptr;
	while (str[size] != '\0') {
		push_back(str[size]);
		size++;
	}
	if (size < 15) {
		string.on_stack[size] = '\0';
	} else {
		string.on_heap[size] = '\0';
	}
}


String::String(const String& oth) : size(oth.size), capacity(oth.capacity) {
	if (size < 15) {
		string.on_heap = nullptr;
		for (int i = 0; i <= oth.size; ++i) {
			string.on_stack[i] = oth.string.on_stack[i];
		}
	} else {
		string.on_heap = new char[capacity];
		for (int i = 0; i <= oth.size; ++i) {
			string.on_heap[i] = oth.string.on_heap[i];
		}
	}
}


void String::create_dynamic() {
	string.on_heap = new char[capacity];
	for (int i = 0; i < size; ++i) {
		string.on_heap[i] = string.on_stack[i];
	}
}


void String::push_back(char ch) {
	const size_t stack_max_size = 16;
	if (size < stack_max_size - 1) {
		string.on_stack[size] = ch;
		string.on_stack[size + 1] = '\0';
	} else {
		if (string.on_heap == nullptr) {
			capacity *= 2;
			create_dynamic();
		} else if (size >= capacity - 1) {
			capacity *= 2;
			char* temp = new char[capacity];
			strcpy(temp, string.on_heap);
			delete [] string.on_heap;
			string.on_heap = temp;
		}
			string.on_heap[size] = ch;
			string.on_heap[size+1] = '\0';
	}
	size++;
}


char String::operator[](size_t index){
	if (index >= size || index < 0) {
		throw std::invalid_argument {"Index is out of range!"};
	}
	if (index < 15) {
		return string.on_stack[index];
	}
	return string.on_heap[index];
}


String& String::operator+(const String& oth) {
	if (oth.size < 15) {
		for (size_t i = 0; i < oth.size; ++i) {
			push_back(oth.string.on_stack[i]);
		}
	} else {
		for (size_t i = 0; i < oth.size; ++i) {
			push_back(oth.string.on_heap[i]);
		}
	}
	return *this;
}


void String::print() {
	if (size < 15) {
		for (int i = 0; i < size; ++i) {
			std::cout << string.on_stack[i];
		}
	} else {
		for (int i = 0; i < size; ++i) {
			std::cout << string.on_heap[i];
		}
	}
	std::cout << std::endl;
}



