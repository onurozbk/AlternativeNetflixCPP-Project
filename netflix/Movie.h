#include<iostream>

using namespace std;

class Movie {
private:
	int MovieId;
	string MovieName;
	int ImdbSoccer;

public:
	Movie();
	void createMovie(string, int);
	void setMovieName(string);
	string getMovieName();
	void setImdbSoccer(int);
	int getImdbSoccer();

	bool operator == (const Movie&);
	friend std::ostream& operator << (std::ostream&, const Movie&);
	int GetMovieId();
};