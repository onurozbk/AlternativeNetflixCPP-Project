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
}


int transectionResult(int transaction)
{

	if (transaction == 0)
	{
		int result;
		cout << endl;
		cout << "Please enter 1 for List all movies: " << endl;
		cout << "Please enter 2 for add new movie: " << endl;
		cout << "Please enter 3 for remove a movie: " << endl;
		cout << "Please enter 4 for search movie: " << endl;
		cout << "Please enter 5 for learn how much movie in the system: " << endl;
		cout << "Please enter 6 for order by imdb soccer: " << endl;
		cout << "Please enter 7 for order by alphabetic: " << endl;
		cin >> result;

		return result;
	}
	else if (transaction > 0)
	{
		return transaction;
	}
	else {
		return  0;
	}
}



int main()
{
	int transaction;
	int userSelectedTransection;
	Movie movie;
	List<Movie> myList(1000);

#pragma region Create 4 Movie
	movie.createMovie("Lord Of The Rings", 9);
	myList.insert(movie);

	movie.createMovie("The Godfather", 10);
	myList.insert(movie);

	movie.createMovie("Matrix", 7);
	myList.insert(movie);

	movie.createMovie("Fight Club", 8);
	myList.insert(movie);
#pragma endregion

	getHeader();

	cout << "Hello World! Welcome to NETFLIX project, for the help please enter 0, for the close project -1: ";



	while (true)
	{
		cin >> transaction;
		userSelectedTransection = transectionResult(transaction);
		if (userSelectedTransection == 1) {//List All Movies
			myList.print();
			cout << "Success, if you need help please enter 0: ";
		}
		else if (userSelectedTransection == 2) {// Add new Movie
			string moviename;
			int imdbsoccer;
			cout << "Please enter movie name: ";
			cin >> moviename;
			cout << "Please enter movie Imdb soccer: ";
			cin >> imdbsoccer;
			movie.createMovie(moviename, imdbsoccer);
			myList.insert(movie);
			cout << "Success, if you need help please enter 0: ";
		}
		else if (userSelectedTransection == 3)
		{
			int movieid;
			bool confirm;
			cout << "Please Enter a movie Id: ";
			cin >> movieid;
			cout << to_string(movieid) << "The movie will be remove are you sure? '1' or '0' ";
			cin >> confirm;
			if (confirm) {
				if (myList.removeMovie(movieid))
				{
					cout << "Success, if you need help please enter 0: ";
				}
				else {
					cout << "Could not be remove";
				}

			}

		}
		else {
			cout << "Could not be implament this step :(";
		}
	}

	system("pause");
	return 0;
}


