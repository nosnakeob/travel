#ifndef _TRAVEL_H_
#define _TRAVEL_H_

#include <string>

using namespace std;

const int MAXSIZE = 100;

typedef struct Table {
	string sta;
	int loca;
}Tables[MAXSIZE];

typedef struct Station {
	bool way;
	int to;
}Stations[MAXSIZE][MAXSIZE];

class MAP
{
public:
	MAP();//
	~MAP();
	bool calcShorPaths();
	void getShorPath(string from, string to);

private:
	int dis[MAXSIZE][MAXSIZE];
	Tables tabls;
	Stations stas;
};

#endif // !_TRAVEL_H_
