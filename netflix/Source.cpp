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
		cout << "To exit the system please enter -1: " << endl;

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

void getHelp() {
	cout << endl;
	cout << "If you need help please enter 0." << endl;
}

int main()
{
	int transaction = 0;
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

	cout << "Hello World! Welcome to NETFLIX project, for the help please enter 0: ";

	while (transaction != -1)
	{
		cin >> transaction;
		userSelectedTransection = transectionResult(transaction);
		if (userSelectedTransection == 1) {//List All Movies
			myList.print();
			cout << "Success...";
		}
		else if (userSelectedTransection == 2) {// Add new Movie
			int imdbsoccer;
			string dummy;
			getline(cin, dummy);
			cout << "Please enter movie name: " << endl;
			string moviename;
			getline(cin, moviename);
			cout << "Please enter movie Imdb soccer: ";
			cin >> imdbsoccer;
			movie.createMovie(moviename, imdbsoccer);
			myList.insert(movie);
			cout << "Success..";
		}
		else if (userSelectedTransection == 3)// remove a movie by id
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
					cout << "Success..";
				}
				else {
					cout << "Could not be remove";
				}
			}
		}
		else if (userSelectedTransection == 4) //search by name
		{
			string keyword;
			cout << "Please enter search keyword: ";
			cin >> keyword;
			myList.searchMovie(keyword);
		}
		else if (userSelectedTransection == 5)
		{
			cout << myList.getCountOfList() << " Movies are in the system." << endl;
		}
		else if (userSelectedTransection == 6)
		{
			myList.sortByImdbSoccer();
			myList.print();
		}
		else if (userSelectedTransection == -1)
		{
			return 0;
		}
		else {
			cout << "Could not be implament this step :(";
		}
		getHelp();
	}

	system("pause");
	return 0;
}


