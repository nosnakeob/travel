#ifndef _TRAVEL_H_
#define _TRAVEL_H_

#include <string>
#include<map>
#include<vector>

using namespace std;

const int INF = 1e9;
const int MVNUM = 20;

enum Ways//2�ֵ��﷽��
{
	ONFOOT,
	CABLEWAY
};

//�ڽӾ���
typedef string VerTexType;//����

typedef struct Arc //��
{
	int way;//2�ֵ��﷽��
	int dis;//����
}ArcType;

class Map
{
public:
	Map();
	~Map();
	bool create();//����̨
	bool setNum(const int vnum, const int anum);//���ö��㡢����
	bool inserVex(const VerTexType v);//���붥����Ϣ��������֪
	bool inserArc(const VerTexType from, const VerTexType to, const ArcType arc);//�������Ϣ
	bool getPaths(const string from, const string to);//��ȡ����·�������������̨
	bool calcShorPaths();//�����е����·
	bool getShorPath(const string from, const string to);//��ȡ���·�����������̨

private:
	VerTexType vexs[MVNUM];//������Ϣ
	map<string, int> location;//��������

	ArcType arcs[MVNUM][MVNUM];//����Ϣ
	int vex_num, arc_num;//������������

	int shor_dis[MVNUM][MVNUM];//����̾���
	int stations[MVNUM][MVNUM];//����̾������ת��

	inline int loca(const VerTexType vex);//�õ���������
	inline bool isIn(const VerTexType name);//�����Ƿ�����ͼ
	inline bool isWay(const VerTexType from, const VerTexType to);//2���Ƿ���·�����ô�����·
	void DFS(const VerTexType vex, const VerTexType end, vector<VerTexType> &path, bool isvisited[]);//���ѣ��������̨

};

#endif // !_TRAVEL_H_
