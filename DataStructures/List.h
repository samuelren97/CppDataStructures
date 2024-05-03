#pragma once

#include <iostream>
#include <functional>

template<class T>
class List {
public:
	List();
	List(const int& initSize);
	~List();

	void forEach(std::function<void(const T&)> func) const;

	void add(const T& value);
	void insert(const int& index, const T& value);
	void remove(const int& index);
	T get(const int& index) const;
	int length() const;
	int getSize() const;

	// LIFO
	T pop();

	void reverse();
	List toReversed();

	T* begin() const;
	T* end() const;

private:
	int size;
	int count;
	T* data;
};

template<class T>
List<T>::List()
	: size(20),
	count(0),
	data(new T[20])
{
	;
}

template<class T>
List<T>::List(const int& initSize)
	: size(initSize),
	count(0),
	data(new T[initSize])
{
	;
}

template<class T>
List<T>::~List() {
	if (this->data) {
		delete[] this->data;
		this->data = nullptr;
	}
}

template<class T>
void List<T>::forEach(std::function<void(const T&)> func) const {
	for (int i = 0; i < this->count; ++i) {
		func(this->data[i]);
	}
}

template<class T>
void List<T>::add(const T& value) {
	insert(this->count, value);
}

template<class T>
void List<T>::insert(const int& index, const T& value) {
	if (index < 0 || index > this->count) {
		throw std::invalid_argument("Index out of bounds");
	}

	if (this->count == this->size) {
		this->size *= 2;
		T* newData = new T[this->size];

		for (int i = 0; i < this->count; ++i) {
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}

	if (index == this->count) {
		this->data[this->count] = value;
	}
	else {
		for (int i = this->count; i > index; --i) {
			this->data[i] = this->data[i - 1];
		}
		this->data[index] = value;
	}

	++this->count;
}

template<class T>
void List<T>::remove(const int& index) {
	if (index < 0 || index >= this->count) {
		throw std::invalid_argument("Index out of bounds");
	}

	if (index != this->count - 1) {
		for (int i = index; i < this->count - 1; ++i) {
			this->data[i] = this->data[i + 1];
		}
	}

	--this->count;
}

template<class T>
T List<T>::get(const int& index) const {
	if (index < 0 || index >= this->count) {
		throw std::invalid_argument("Index out of bounds");
	}

	return this->data[index];
}

template<class T>
int List<T>::length() const {
	return this->count;
}

template<class T>
int List<T>::getSize() const {
	return this->size;
}

template<class T>
T List<T>::pop() {
	T last = this->data[this->count - 1];
	remove(this->count - 1);
	return last;
}

template<class T>
void List<T>::reverse() {
	T* newData = new T[this->size];
	for (int i = this->count - 1; i >= 0; --i) {
		newData[(this->count - 1) - i] = this->data[i];
	}
	delete[] this->data;
	this->data = newData;
}

template<class T>
List<T> List<T>::toReversed() {
	List<T> newList(this->size);
	for (int i = this->count - 1; i >= 0; --i) {
		newList.add(this->data[i]);
	}
	return newList;
}

template<class T>
T* List<T>::begin() const {
	return this->data;
}

template<class T>
T* List<T>::end() const {
	return this->data + this->count;
}