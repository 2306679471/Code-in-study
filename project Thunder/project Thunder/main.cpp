#include<iostream>
#include"pp.h"
using namespace std;

My my = { 0, 0, 0, 10, 10, 10, 0, 0, nullptr };
char Begin[4][1] = {
		{ 10 },
		{ 2 },
		{ 3 },
		{ 4 }
};

int main()
{
	My *x = &my, *y = &my;
	while (true)
	{
		//游戏开始界面
		int GB = GameBegin(&my);
		if (1 == GB)
		{
			system("CLS");//清屏
			//初始化地图
			DefinMap(&my);
			//布雷
			UpLand(&my);
			//计算周围雷的数量
			CalLand(&my);
			while (true)
			{
				//打印地图
				PrintMap(&my);
				//按键响应
				KeyControl(&my);

				OpenMap(&my);
				x->OffsetX = 0;
				y->OffsetY = 0;

				//胜利与失败判断
				int VS = VictoryC(&my);
				if (1 == VS)
				{
					cout << "游戏胜利！" << endl;
					return 0;
				}
				else if (0 == VS)
				{
					cout << "游戏失败！" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}