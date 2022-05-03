#include<iostream>
#include<time.h>
#include<conio.h>
#include"pp.h"
using namespace std;
extern My my;
extern char Begin[4][1];
//游戏开始界面
int GameBegin(My *my)
{
		cout << "****************扫雷***************" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				switch (Begin[i][j])
				{
				
				case 1:
					cout << "   初级（10个雷）" << endl;
					break;
				case 10:
					cout << "☆ 初级（10个雷）" << endl;
					break;

				case 2:
					cout << "   中级（40个雷）" << endl;
					break;
				case 20:
					cout << "☆ 中级（40个雷）" << endl;
					break; 

				case 3:
					cout << "   高级（99个雷）" << endl;
					break;
				case 30:
					cout << "☆ 高级（99个雷）" << endl;
					break;

				case 4:
					cout << "   自定义" << endl;
					break;
				case 40:
					cout << "☆ 自定义" << endl;
					break;
				}
			}
		}
		
		int Input = _getch();//提取按键
		switch (Input)
		{
		case 's':
		case 'S':
			if (my->n < 3)
			{
				Begin[my->n][0] /= 10;
				my->n++;
				Begin[my->n][0] *= 10;
			}
			break;
		case 'w':
		case 'W':
			if (my->n > 0)
			{
				Begin[my->n][0] /= 10;
				my->n--;
				Begin[my->n][0] *= 10;
			}
			break;
		case ' ':
			if (0 == my->n)
			{
				my->row = 9;
				my->col = 9;
				my->la = 10;
				return 1;
			}
			else if (1 == my->n)
			{
				my->row = 16;
				my->col = 16;
				my->la = 40;
				return 1;
			}
			else if (2 == my->n)
			{
				my->row = 30;
				my->col = 16;
				my->la = 99;
				return 1;
			}
			if (3 == my->n)
			{
				while (1)
				{
					int x, y, l;
					system("CLS");//清屏
					cout << "*************自定义**************" << endl;
					cout << endl;
					cout << "请输入行、列和雷的数量：";
					cin >> x >> y >> l;
					if (l < x*y)
					{
						my->row = x;
						my->col = y;
						my->la = l;
						return 1;
					}
					else
					{ 
						cout << "您的输入有误！请选择是否返回模式选择界面。" << endl;\
						cout << "返回游戏界面请输入1：" ;
						int key;
						cin >> key;
						if (1 == key)
						{
							system("CLS");//清屏
							return 0;
						}	
					}
				}
			}
			break;
		}
		system("CLS");//清屏
	return 0;
}



//初始化地图
void DefinMap(My *my)
{
	my->PGameMap = new int*[my->row];//申请一段内存，保存每一行的首地址

	for (int i = 0; i < my->row; i++)
	{
		my->PGameMap[i] = new int[my->col];//申请每一行元素的内存地址，并把首地址保存到PMap对应的内存中
	}
	//初始化
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j <my->col; j++)
		{
			my->PGameMap[i][j] = 0;
		}
	}
}


//布雷
void UpLand(My *my)
{
	srand(time(nullptr));
	for (int i = 0, n = my->la; n > 0 && i < my->row; i++)
	{
		for (int j = 0; n > 0 && j < my->col; j++)
		{
			my->PGameMap[i][j] = 9;
			n--;
		}
	}

	//当前的元素与随机的行列下标元素交换
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			int r = rand() % my->row;
			int l = rand() % my->col;
			int Temp = my->PGameMap[i][j];
			my->PGameMap[i][j] = my->PGameMap[r][l];
			my->PGameMap[r][l] = Temp;
		}
	}
}

//计算周围雷的数量
void CalLand(My *my)
{
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			if (my->PGameMap[i][j] != 9)
			{
				int count = 0;//统计雷的数量
				for (int r = -1; r <= 1; r++)
				{
					for (int l = -1; l <= 1; l++)
					{
						if (i + r >= 0 && i + r < my->row && j + l >= 0 && j + l < my->col && 9 == my->PGameMap[i + r][j + l])
						{
							++count;
						}
					}
				}
				my->PGameMap[i][j] = count;
			}
		}
	}
	//设置玩家起始位置
	my->PGameMap[0][0] += 20;
}


//打印地图
void PrintMap(My *my)
{
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			switch (my->PGameMap[i][j])
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				cout << "■";
				break;
			case 10:
			case 50:
				cout << "  ";
				break;
			case 11:
				cout << "①";
				break;
			case 12:
				cout << "②";
				break;
			case 13:
				cout << "③";
				break;
			case 14:
				cout << "④";
				break;
			case 15:
				cout << "⑤";
				break;
			case 16:
				cout << "⑥";
				break;
			case 17:
				cout << "⑦";
				break;
			case 18:
				cout << "⑧";
				break;
			case 19:
				cout << "¤";
				break;
			case 20:
			case 21:
			case 22:
			case 23:
			case 24:
			case 25:
			case 26:
			case 27:
			case 28:
			case 29:
			case 30:
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			case 38:
			case 39:
			case 70:
				cout << "□";
				break;
			}

		}
		cout << endl;
	}
}



//按键响应
void KeyControl(My *my)
{
	int Input = _getch();//提取按键
	switch (Input)
	{
	case 's':
	case 'S':
		if (my->TopX < my->col - 1)//防止越界
		{
			//如果当前元素是标记玩家本身那么移动时当前元素-20，恢复为未标记玩家本身
			if (my->PGameMap[my->TopX][my->TopY] >= 20 && my->PGameMap[my->TopX][my->TopY] < 40|| 70 == my->PGameMap[my->TopX][my->TopY])
			{
				my->PGameMap[my->TopX][my->TopY] -= 20;
			}
			//玩家位置移动
			my->TopX += 1;
			//标记玩家
			my->PGameMap[my->TopX][my->TopY] += 20;
		}
		break;
	case'w':
	case'W':
		if (my->TopX > 0)
		{
			if (my->PGameMap[my->TopX][my->TopY] >= 20 && my->PGameMap[my->TopX][my->TopY] < 40 || 70 == my->PGameMap[my->TopX][my->TopY])
				my->PGameMap[my->TopX][my->TopY] -= 20;
			my->TopX -= 1;
			my->PGameMap[my->TopX][my->TopY] += 20;
		}
		break;
	case'a':
	case'A':
		if (my->TopY > 0)
		{
			if (my->PGameMap[my->TopX][my->TopY] >= 20 && my->PGameMap[my->TopX][my->TopY] < 40 || 70 == my->PGameMap[my->TopX][my->TopY])
				my->PGameMap[my->TopX][my->TopY] -= 20;
			my->TopY -= 1;
			my->PGameMap[my->TopX][my->TopY] += 20;
		}
		break;
	case'd':
	case'D':
		if (my->TopY < my->row - 1)
		{
			if (my->PGameMap[my->TopX][my->TopY] >= 20 && my->PGameMap[my->TopX][my->TopY] < 40 || 70 == my->PGameMap[my->TopX][my->TopY])
				my->PGameMap[my->TopX][my->TopY] -= 20;
			my->TopY += 1;
			my->PGameMap[my->TopX][my->TopY] += 20;
		}
		break;
	case' ':
		if (my->PGameMap[my->TopX][my->TopY] < 30 && my->PGameMap[my->TopX][my->TopY] >= 20)
		{
			my->PGameMap[my->TopX][my->TopY] -= 10;
		}
		break;
	}
	system("CLS");//清屏
}


//胜利与失败判断
int VictoryC(My *my)
{

	int n = 0;
	//游戏失败
	if (19 == my->PGameMap[my->TopX][my->TopY])
	{
		return 0;
	}
	//判断游戏是否继续
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			//判断是否除雷外全部找出
			if (my->PGameMap[i][j] >= 10 && my->PGameMap[i][j] <= 18 || my->PGameMap[i][j] >= 30 && my->PGameMap[i][j] <= 38 || 50 == my->PGameMap[i][j] || 70 == my->PGameMap[i][j])
				n++;
		}
	}
	//游戏胜利
	if (n == my->row * my->col - my->la)
	{
		return 1;
	}
	return 2;
}

//选中周围0地雷展开
void OpenMap(My *My)
{

	if (10 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])//未标记的进行遍历
	{
		My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] += 40;//给当前为空的标记,标记的将不在进行遍历
		if (50 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])
		{ 
			My->OffsetX -= 1;My->OffsetY -= 1;//初始从九宫格的左上角开始 
			for (int i = 0; i < 3; i++)
			{
				if (i > 0)
					My->OffsetX += 1;//在一个九宫格里循环
				for (int j = 0; j < 3; j++)
				{
					if (j > 0)
						My->OffsetY += 1;//在一个九宫格里循环
					if (My->TopY + My->OffsetY >= 0 && My->TopY + My->OffsetY<My->col && My->TopX + My->OffsetX >= 0 && My->TopX + My->OffsetX<My->row)//控制不越界
					{ 
						if (My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] < 9)//没有打开的让其打开
						{
							My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] += 10;//打开
							if (10 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])//打开后为空的,进行递归
							{
								OpenMap(&my);//递归
							}
						}
					}
				}
				My->OffsetY -= 2;//当横排的三个遍历完，让其恢复到最前面那个位置
			}
			//当当前的九宫格都遍历完了恢复到中间位置
			My->OffsetX -= 1;
			My->OffsetY += 1;
		}
	}
}


