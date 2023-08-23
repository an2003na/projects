#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
public:
	//default constructor
	Vector() : arr(0), size(0), capacity(0) {}
	//constructor with parameters
	explicit Vector(int cap) : arr(new T[cap]),
			size(0), capacity(cap) {}
	void push_back(T);
	void pop_back();
	void push_front(T);
	void pop_front();
	void insert(int, T);
	void remove(int);
	void print();
	int length() { return size; }
	void clear() {
		size = 0;
		delete [] arr;
		arr = nullptr;
       	}
	T& operator[](int);
	~Vector() {
		delete [] arr;
		arr = nullptr;
	}

private:
	T* arr;
	int size;
	int capacity;
};


/* The function gets an element in argument
 * and adds that element to the end of the vector
 */
template <typename T>
void Vector<T>::push_back(T elem) {
	if (size == 0) {
		capacity++;
		arr = new T[capacity];
		arr[0] = elem;
		size++;
		return;
	}
	if (size == capacity) {
		capacity *= 2;
		T* tmp = new T[capacity];
		for (int i{}; i < size; ++i) {
			tmp[i] = arr[i];
		}
		delete [] arr;
		arr = tmp;
	}
	arr[size] = elem;
	size++;
}


/* The function removes the last element of the vector
 */
template <typename T>
void Vector<T>::pop_back() {
	size--;
}


/* The function gets an element in argument
 * and adds that element to the beginning of the vector
 */
template <typename T>
void Vector<T>::push_front(T elem) {
	if (size == capacity) {
		capacity *= 2;
	}
	T* tmp = new T[capacity];
	tmp[0] = elem;
	for (int i{}; i < size; ++i) {
		tmp[i + 1] = arr[i];
	}
	delete [] arr;
	arr = tmp;
	size++;
}


/* The function removes the first element of the vector */
template <typename T>
void Vector<T>::pop_front() {
	for (int i{}; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0;
	size--;
}


/* The function gets a position and an element in argument
 * and adds the element in that position of the vector
 */
template <typename T>
void Vector<T>::insert(int pos, T elem) {
	if (pos > capacity || pos < 0) {
		throw std::invalid_argument {"index is out of range!"};
	}
	if (pos == capacity) {
		capacity *= 2;
	}
	T* tmp = new T[capacity];
	for (int i{}, k{}; i <= size; ++i, ++k) {
		if (i == pos) {
			tmp[i] = elem;
			k++;
		}
		tmp[k] = arr[i];
	}
	delete [] arr;
	arr = tmp;
	size++;
}


/* The function gets a position in argument and removes
 * the element from that position in the vector
 */
template <typename T>
void Vector<T>::remove(int pos) {
	if (pos >= size) {
		throw std::invalid_argument {"index is out of range!"};
	}
	T* tmp = new T[capacity];
	for (int i{}, k{}; i < size - 1; ++i, ++k) {
		if (i == pos) {
			k++;
			continue;
		}
		tmp[i] = arr[k];
	}
	delete [] arr;
	arr = tmp;
	--size;
}


/* operator[] overloading */
template <typename T>
T& Vector<T>::operator[](int index) {
	if (index >= size) {
		throw std::invalid_argument {"Index is out of range!"};
	}
	return arr[index];
}


/* The function prints the vector */
template <typename T>
void Vector<T>::print() {
	if (size == 0) {
		throw std::invalid_argument { "The vector is empty." };
	}
	for (int i{}; i < size; ++i) {
		std::cout << "Vector[" << i << "] = " << arr[i] << std::endl;
	}
}


#endif
