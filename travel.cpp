#include"travel.h"
#include<iostream>
#include<stack>

using namespace std;


Map::Map()
{
	arc_num = vex_num = 0;

	for (int i = 0; i < MVNUM; i++)
	{
		for (int j = 0; j < MVNUM; j++)
		{
			if (i == j)
			{
				arcs[i][j].dis = shor_dis[i][j] = 0;
			}
			else
			{
				arcs[i][j].dis = shor_dis[i][j] = INF;
			}
			stations[i][j] = j;
		}
	}


}

Map::~Map()
{
}

bool Map::create()
{
	VerTexType from, to, ver;
	ArcType arc;
	int vnum, anum;
	cout << "请输入顶点、边个数(vex<" << MVNUM << "):";
	cin >> vnum >> anum;
	while (!setNum(vnum, anum))
	{
		cout << "非法数字！请重新输入" << endl;
		cin >> vnum >> anum;
	}

	cout << "请输入顶点名字:";
	for (int i = 0; i < vnum; i++)
	{
		cin >> ver;
		inserVex(ver);
	}

	cout << "请输入起点、终点、路程、到达方法(步行:" << ONFOOT << "/索道:" << CABLEWAY << "):" << endl;
	int i = 0;
	while (i < anum)
	{
		cin >> from >> to >> arc.dis >> arc.way;
		if (!inserArc(from, to, arc))
		{
			cout << "边信息有误，请检查" << endl;
			continue;
		}
		i++;
	}

	calcShorPaths();

	return true;
}

bool Map::setNum(const int vnum, const int anum)
{
	if (vnum <= 1 || anum < 1 || vnum >= MVNUM)		return false;

	vex_num = vnum;
	arc_num = anum;
	return true;
}

bool Map::inserVex(const VerTexType v)
{
	static int i = 1;

	if (i > vex_num)
	{
		i = 1;
		return false;
	}

	vexs[i] = v;
	location[v] = i;
	i++;

	return true;
}

bool Map::inserArc(const VerTexType from, const VerTexType to, const ArcType arc)
{
	static int i = 0;

	if (i >= arc_num)
	{
		i = 0;
		return false;
	}

	if (!isIn(from) || !isIn(to)) return false;

	int f = loca(from), t = loca(to);
	arcs[f][t] = arc;
	shor_dis[f][t] = arc.dis;
	i++;

}

bool Map::getPaths(const string from, const string to)
{
	if (!isIn(from) || !isIn(to))	return false;

	if (!isWay(from, to))	return false;

	vector<VerTexType> path;
	bool isvisited[MVNUM] = { 0 };
	DFS(from, to, path, isvisited);

	return true;
}

void Map::DFS(const VerTexType vex, const VerTexType end, vector<VerTexType>& path, bool isvisited[])
{
	int v = loca(vex);
	path.push_back(vex);
	isvisited[v] = 1;

	if (vex == end)//到达目的地
	{
		int dis = 0;
		for (int i = 0; i < path.size() - 1; i++)
		{
			int f = loca(path[i]), t = loca(path[i + 1]);
			cout << path[i]
				<< (arcs[f][t].way == ONFOOT ? "->" : "=>");
			dis += arcs[f][t].dis;
		}
		cout << *(path.end() - 1) << "	dis=" << dis << endl;
		return;
	}

	for (int to = 1; to <= vex_num; to++)
		if (arcs[v][to].dis != INF && !isvisited[to])//遍历能走、未访问的点
		{
			DFS(vexs[to], end, path, isvisited);
			path.pop_back();
			isvisited[to] = 0;
		}

	return;
}


inline int Map::loca(const VerTexType vex)
{
	return location[vex];
}
inline bool Map::isIn(const VerTexType name)
{
	return location[name];
}

inline bool Map::isWay(const VerTexType from, const VerTexType to)
{
	int f = loca(from), t = loca(to);
	if (shor_dis[f][t] >= INF)		return false;
	return true;
}

bool Map::calcShorPaths()//Floyd-Warshall
{
	for (int sta = 1; sta <= vex_num; sta++)//中转点
	{
		for (int f = 1; f <= vex_num; f++)
		{
			for (int t = 1; t <= vex_num; t++)
			{
				if (shor_dis[f][sta] + shor_dis[sta][t] < shor_dis[f][t])
				{
					shor_dis[f][t] = shor_dis[f][sta] + shor_dis[sta][t];
					stations[f][t] = sta;
				}
			}
		}
	}

	return true;
}

bool Map::getShorPath(const string from, const string to)
{
	if (!isIn(from) || !isIn(to))	return false;

	int v, f = v = loca(from), t = loca(to);

	if (!isWay(from, to))	return false;

	cout << "dis=" << shor_dis[f][t] << endl;

	while (v != t)
	{
		cout << vexs[v] << (arcs[v][t].way == ONFOOT ? "->" : "=>");
		v = stations[v][t];
	}
	cout << vexs[t] << endl;

}