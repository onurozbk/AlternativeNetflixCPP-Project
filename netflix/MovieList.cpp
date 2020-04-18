#include "MovieList.h"

template <typename T>
MovieList<T>::MovieList(unsigned int maxLength) {
	this->maxLength = maxLength;
	array = new T[this->maxLength]; // dynamic allocation
	this->length = 0;
}
template <typename T>
MovieList<T>::~MovieList()
{	// do cleaning when the list is no more needed
	delete[] array;}
template <typename T>
bool MovieList<T>::isFull() const {
	return (this->length == this->maxLength);
}

template <typename T>
bool MovieList<T>::isEmpty() const {
	return (this->length == 0);
}

template <typename T>
unsigned int MovieList<T>::getLength() const {
	return this->length;
}

template <typename T>
void MovieList<T>::retrieve(T& item, bool& found) const {
	int currentLocation = 0;
	found = false;
	bool moreToSearch = (currentLocation < this->length);
	while (moreToSearch && !found) {
		if (item == array[currentLocation]) {
			found = true;
			std::cout << array[currentLocation] << std::endl;
		}
		else {
			currentLocation++;
			moreToSearch = (currentLocation < this->length);
		}
	}
}template <typename T>
void MovieList<T>::insert(T item) {
	if (this->isFull()) {
		std::cout << "Not inserted !!! List is full." << std::endl;
		return;
	}
	array[this->length] = item;
	this->length++;
}template <typename T>
void MovieList<T>::print() const {
	for (int i = 0; i < this->length; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}