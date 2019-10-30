#include"travel.h"
#include<iostream>

using namespace std;


MAP::MAP()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			dis[i][j] = 0;
			stas[i][j].to = stas[i][j].way = 0;
		}
	}
}

MAP::~MAP()
{
}

bool MAP::calcShorPaths()
{
	return false;
}

void MAP::getShorPath(string from, string to)
{
}
