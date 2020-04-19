#include<iostream>
#include "string"
using namespace std;
template <typename T>

class List {
private:
	int max_movie;
	int ListOfCount;
	T* array;


public:
	List(unsigned int max_movie) {
		this->max_movie = max_movie;
		array = new T[this->max_movie]; // dynamic allocation
		this->ListOfCount = 0;
	}

	bool isFull() const {
		return (this->ListOfCount == this->max_movie);
	}

	bool isEmpty() const {
		return (this->ListOfCount == 0);
	}

	unsigned int getCountOfList() const {
		return this->ListOfCount;
	}

	bool found_delete(int id) {

		for (int i = 0; i < ListOfCount; i++) {
			if (id == array[i]) {
				array[i] = array[ListOfCount - 1];
				this->ListOfCount--;
				return true;
			}
		}
		return false;
	}

	void insert(T entity) {
		if (this->isFull()) {
			std::cout << "Not inserted !!! List is full." << std::endl;
			return;
		}

		array[this->ListOfCount] = entity;
		this->ListOfCount++;
	}

	void remove(T entity) {
		if (this->isEmpty()) return;
		for (int i = 0; i < this->ListOfCount; i++) {
			if (entity == array[i]) {
				array[i] = array[ListOfCount - 1];
				this->ListOfCount--;
				return;
			}
		}
	}

	void makeEmpty() {
		this->ListOfCount = 0;
	}

	void print() const {
		std::cout << endl;
		for (int i = 0; i < this->ListOfCount; i++) {
			std::cout << array[i] << " " << endl;
		}
		std::cout << std::endl;
	}

	bool removeMovie(int Id) {
		if (this->isEmpty()) return false;
		for (int i = 0; i < this->ListOfCount; i++) {
			if (Id == array[i].GetMovieId()) {
				array[i] = array[ListOfCount - 1];
				this->ListOfCount--;
				return true;
			}
		}
		return false;
	}

	void searchMovie(string keyword)
	{
		std::cout << endl;
		for (int i = 0; i < this->ListOfCount; i++) {
			string movieName = array[i].getMovieName();
			size_t found = movieName.find(keyword);
			if (found != string::npos)
			{
				std::cout << array[i] << " " << endl;
			}
		}
		std::cout << std::endl;
	}

	void sortByImdbSoccer()
	{
		T tmp;
		for (int i = 0; i < ListOfCount - 1; i++)
			for (int j = i + 1; j < ListOfCount; j++)
				if (array[i].getImdbSoccer() < array[j].getImdbSoccer())
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
	}
};