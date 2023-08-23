#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>
#include <stdexcept>


class String
{
public:
	String() : string(), size(0), capacity(16) {
		string.on_heap = nullptr;
		string.on_stack[size] = '\0';
	}
	String(const char*);
	String(const String&);
	size_t length() const { return size; }
	void create_dynamic();
	void push_back(char);
	void print();
	char operator[](size_t);
	String& operator+(const String&);
	~String() { 
		if (capacity > 16) {
			delete [] string.on_heap; 
		}
	}


private:
	struct {
		char on_stack[16];
		char* on_heap;
	} string;
	size_t size;
	size_t capacity;
};


#endif
