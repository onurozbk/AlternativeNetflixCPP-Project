#include<iostream>
#include <string>
#include "Movie.h"

static int _movieid = 1;

Movie::Movie() {
}

void Movie::setMovie(string moviename, int imdbsoccer) {
	this->MovieId = _movieid++;
	this->MovieName = moviename;
	this->ImdbSoccer = imdbsoccer;
}

int Movie::GetMovieId() 
{
	return this->MovieId;
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





