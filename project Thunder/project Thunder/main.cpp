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
		//��Ϸ��ʼ����
		int GB = GameBegin(&my);
		if (1 == GB)
		{
			system("CLS");//����
			//��ʼ����ͼ
			DefinMap(&my);
			//����
			UpLand(&my);
			//������Χ�׵�����
			CalLand(&my);
			while (true)
			{
				//��ӡ��ͼ
				PrintMap(&my);
				//������Ӧ
				KeyControl(&my);

				OpenMap(&my);
				x->OffsetX = 0;
				y->OffsetY = 0;

				//ʤ����ʧ���ж�
				int VS = VictoryC(&my);
				if (1 == VS)
				{
					cout << "��Ϸʤ����" << endl;
					return 0;
				}
				else if (0 == VS)
				{
					cout << "��Ϸʧ�ܣ�" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}