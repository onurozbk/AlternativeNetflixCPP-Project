#include <iostream>
#include <string>
#include "List.h"
#include "Movie.h"
using namespace std;

void getHeader() {
	cout << "      ___ ___  ___             " << endl;
	cout << "|\\ | |__   |  |__  |    | \\_/  " << endl;
	cout << "| \\| |___  |  |    |___ | / \\ " << endl;
	cout << endl;
	cout << endl;

	cout << "Hello World! Welcome to NETFLIX project, for the help please enter 0, for the close project -1: ";
}


void transectionResult(int transection)
{
	if (transection > 0)
	{
		cout << endl;
		cout << "Please enter 1 for add new movie: " << endl;
		cout << "Please enter 2 for search movie: " << endl;
		cout << "Please enter 3 for learn how much movie in the system: " << endl;
		cout << "Please enter 4 for order by imdb soccer: " << endl;
		cout << "Please enter 4 for order by alphabetic: " << endl;
	}
	else
	{
		return;
	}

}


int main()
{
	getHeader();

	int transection;
	//cin >> transection;
	//transectionResult(transection);

	List<Movie> myList(1000);
	Movie movie;
	movie.setMovie("Lord Of The Rings", 9);
	myList.insert(movie);

	movie.setMovie("The Godfather", 10);
	myList.insert(movie);

	movie.setMovie("Matrix", 7);
	myList.insert(movie);

	movie.setMovie("Fight Club", 8);
	myList.insert(movie);

	myList.print();
	myList.removeMovie(2);
	myList.print();


#pragma region List of Int
	List<int> myIntList(5);
	myIntList.insert(1);
	myIntList.insert(2);
	myIntList.insert(3);
	myIntList.insert(4);
	myIntList.insert(5);
	myIntList.print();
	myIntList.remove(3);
	myIntList.print();
#pragma endregion

	system("pause");
	return 0;
}


