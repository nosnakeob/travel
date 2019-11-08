#ifndef _TRAVEL_H_
#define _TRAVEL_H_

#include <string>
#include<map>
#include<vector>

using namespace std;

const int INF = 1e9;
const int MVNUM = 20;

enum Ways//2种到达方法
{
	ONFOOT,
	CABLEWAY
};

//邻接矩阵
typedef string VerTexType;//顶点

typedef struct Arc //边
{
	int way;//2种到达方法
	int dis;//距离
}ArcType;

class Map
{
public:
	Map();
	~Map();
	bool create();//控制台
	bool setNum(const int vnum, const int anum);//设置顶点、边数
	bool inserVex(const VerTexType v);//插入顶点信息、个数已知
	bool inserArc(const VerTexType from, const VerTexType to, const ArcType arc);//插入边信息
	bool getPaths(const string from, const string to);//获取所有路径，输出到控制台
	bool calcShorPaths();//算所有的最短路
	bool getShorPath(const string from, const string to);//获取最短路，输出到控制台

private:
	VerTexType vexs[MVNUM];//顶点信息
	map<string, int> location;//顶点坐标

	ArcType arcs[MVNUM][MVNUM];//边信息
	int vex_num, arc_num;//顶点数、边数

	int shor_dis[MVNUM][MVNUM];//存最短距离
	int stations[MVNUM][MVNUM];//各最短距离的中转点

	inline int loca(const VerTexType vex);//得到顶点坐标
	inline bool isIn(const VerTexType name);//顶点是否属于图
	inline bool isWay(const VerTexType from, const VerTexType to);//2点是否有路、利用存的最短路
	void DFS(const VerTexType vex, const VerTexType end, vector<VerTexType> &path, bool isvisited[]);//深搜，输出控制台

};

#endif // !_TRAVEL_H_
