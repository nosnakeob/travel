#include <iostream>
#include"travel.h"
#include<Windows.h>

using namespace std;

enum Option
{
	CREATE = 1,
	FINDALL,
	FINDSHOR,
	EXIT
};

void Menu()
{
	cout << "---------------------------------------------------------------------" << endl
		<< "                          旅游景点查询" << endl
		<< "1. 创建 " << endl
		<< "2. 查找所有路径" << endl
		<< "3. 查找最短路径" << endl
		<< "4. 退出程序" << endl
		<< "---------------------------------------------------------------------" << endl;
}

int main()
{
	//freopen("test.in", "r", stdin);

	Map travel;
	VerTexType from, to, ver;

	while (true)
	{
		system("cls");
		Menu();
		int o;
		cin >> o;

		switch (o)
		{
		case CREATE:

			travel.create();
			cout << "创建成功" << endl;

			break;

		case FINDALL:
			cout << "请输入要查找所有路径的两个景点:";
			cin >> from >> to;
			if (!travel.getPaths(from, to))
			{
				cout << "景点不存在/不可达" << endl;
			}

			system("pause");
			break;

		case FINDSHOR:

			cout << "请输入要查找最短路径的两个景点:";
			cin >> from >> to;
			if (!travel.getShorPath(from, to))
			{
				cout << "景点不存在/不可达" << endl;
			}

			system("pause");
			break;

		case EXIT:
			cout << "正在退出..." << endl;
			Sleep(500);
			exit(-1);

		default:
			cout << "非法输入！请重试" << endl;

			break;
		}

		Sleep(1000);

	}


	//fclose(stdin);

	return 0;
}
