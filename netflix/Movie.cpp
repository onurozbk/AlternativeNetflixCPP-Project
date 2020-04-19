#include<iostream>
#include <string>
#include "Movie.h"

static int _movieid = 1;

Movie::Movie() {
}

void Movie::createMovie(string moviename, int imdbsoccer) {
	this->MovieId = _movieid++;
	this->MovieName = moviename;
	this->ImdbSoccer = imdbsoccer;
}

int Movie::GetMovieId() 
{
	return this->MovieId;
}

void Movie::setMovieName(string movieName)
{
	this->MovieName = movieName;
}
string Movie::getMovieName() 
{
	return this->MovieName;
}

void Movie::setImdbSoccer(int imdbsoccer)
{
	this->ImdbSoccer = imdbsoccer;
}

int Movie::getImdbSoccer()
{
	return this->ImdbSoccer;
}


bool Movie::operator == (const Movie& otherItem) {
	if (this->MovieId == otherItem.MovieId)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, const Movie& item) {
	os << to_string(item.MovieId) + " " + item.MovieName + " " + to_string(item.ImdbSoccer);
	return os;
}





