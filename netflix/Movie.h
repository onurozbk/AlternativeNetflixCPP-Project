#include<iostream>

using namespace std;

class Movie {
private:
	int MovieId;
	string MovieName;
	int ImdbSoccer;

public:
	Movie();
	void setMovie(string, int);
	bool operator == (const Movie&);
	friend std::ostream& operator << (std::ostream&, const Movie&);
	int GetMovieId();
};