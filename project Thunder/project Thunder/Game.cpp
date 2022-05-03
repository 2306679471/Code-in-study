#include<iostream>
#include<time.h>
#include<conio.h>
#include"pp.h"
using namespace std;
extern My my;
extern char Begin[4][1];
//��Ϸ��ʼ����
int GameBegin(My *my)
{
		cout << "****************ɨ��***************" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				switch (Begin[i][j])
				{
				
				case 1:
					cout << "   ������10���ף�" << endl;
					break;
				case 10:
					cout << "�� ������10���ף�" << endl;
					break;

				case 2:
					cout << "   �м���40���ף�" << endl;
					break;
				case 20:
					cout << "�� �м���40���ף�" << endl;
					break; 

				case 3:
					cout << "   �߼���99���ף�" << endl;
					break;
				case 30:
					cout << "�� �߼���99���ף�" << endl;
					break;

				case 4:
					cout << "   �Զ���" << endl;
					break;
				case 40:
					cout << "�� �Զ���" << endl;
					break;
				}
			}
		}
		
		int Input = _getch();//��ȡ����
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
					system("CLS");//����
					cout << "*************�Զ���**************" << endl;
					cout << endl;
					cout << "�������С��к��׵�������";
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
						cout << "��������������ѡ���Ƿ񷵻�ģʽѡ����档" << endl;\
						cout << "������Ϸ����������1��" ;
						int key;
						cin >> key;
						if (1 == key)
						{
							system("CLS");//����
							return 0;
						}	
					}
				}
			}
			break;
		}
		system("CLS");//����
	return 0;
}



//��ʼ����ͼ
void DefinMap(My *my)
{
	my->PGameMap = new int*[my->row];//����һ���ڴ棬����ÿһ�е��׵�ַ

	for (int i = 0; i < my->row; i++)
	{
		my->PGameMap[i] = new int[my->col];//����ÿһ��Ԫ�ص��ڴ��ַ�������׵�ַ���浽PMap��Ӧ���ڴ���
	}
	//��ʼ��
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j <my->col; j++)
		{
			my->PGameMap[i][j] = 0;
		}
	}
}


//����
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

	//��ǰ��Ԫ��������������±�Ԫ�ؽ���
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

//������Χ�׵�����
void CalLand(My *my)
{
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			if (my->PGameMap[i][j] != 9)
			{
				int count = 0;//ͳ���׵�����
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
	//���������ʼλ��
	my->PGameMap[0][0] += 20;
}


//��ӡ��ͼ
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
				cout << "��";
				break;
			case 10:
			case 50:
				cout << "  ";
				break;
			case 11:
				cout << "��";
				break;
			case 12:
				cout << "��";
				break;
			case 13:
				cout << "��";
				break;
			case 14:
				cout << "��";
				break;
			case 15:
				cout << "��";
				break;
			case 16:
				cout << "��";
				break;
			case 17:
				cout << "��";
				break;
			case 18:
				cout << "��";
				break;
			case 19:
				cout << "��";
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
				cout << "��";
				break;
			}

		}
		cout << endl;
	}
}



//������Ӧ
void KeyControl(My *my)
{
	int Input = _getch();//��ȡ����
	switch (Input)
	{
	case 's':
	case 'S':
		if (my->TopX < my->col - 1)//��ֹԽ��
		{
			//�����ǰԪ���Ǳ����ұ�����ô�ƶ�ʱ��ǰԪ��-20���ָ�Ϊδ�����ұ���
			if (my->PGameMap[my->TopX][my->TopY] >= 20 && my->PGameMap[my->TopX][my->TopY] < 40|| 70 == my->PGameMap[my->TopX][my->TopY])
			{
				my->PGameMap[my->TopX][my->TopY] -= 20;
			}
			//���λ���ƶ�
			my->TopX += 1;
			//������
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
	system("CLS");//����
}


//ʤ����ʧ���ж�
int VictoryC(My *my)
{

	int n = 0;
	//��Ϸʧ��
	if (19 == my->PGameMap[my->TopX][my->TopY])
	{
		return 0;
	}
	//�ж���Ϸ�Ƿ����
	for (int i = 0; i < my->row; i++)
	{
		for (int j = 0; j < my->col; j++)
		{
			//�ж��Ƿ������ȫ���ҳ�
			if (my->PGameMap[i][j] >= 10 && my->PGameMap[i][j] <= 18 || my->PGameMap[i][j] >= 30 && my->PGameMap[i][j] <= 38 || 50 == my->PGameMap[i][j] || 70 == my->PGameMap[i][j])
				n++;
		}
	}
	//��Ϸʤ��
	if (n == my->row * my->col - my->la)
	{
		return 1;
	}
	return 2;
}

//ѡ����Χ0����չ��
void OpenMap(My *My)
{

	if (10 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])//δ��ǵĽ��б���
	{
		My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] += 40;//����ǰΪ�յı��,��ǵĽ����ڽ��б���
		if (50 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])
		{ 
			My->OffsetX -= 1;My->OffsetY -= 1;//��ʼ�ӾŹ�������Ͻǿ�ʼ 
			for (int i = 0; i < 3; i++)
			{
				if (i > 0)
					My->OffsetX += 1;//��һ���Ź�����ѭ��
				for (int j = 0; j < 3; j++)
				{
					if (j > 0)
						My->OffsetY += 1;//��һ���Ź�����ѭ��
					if (My->TopY + My->OffsetY >= 0 && My->TopY + My->OffsetY<My->col && My->TopX + My->OffsetX >= 0 && My->TopX + My->OffsetX<My->row)//���Ʋ�Խ��
					{ 
						if (My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] < 9)//û�д򿪵������
						{
							My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY] += 10;//��
							if (10 == My->PGameMap[My->TopX + My->OffsetX][My->TopY + My->OffsetY])//�򿪺�Ϊ�յ�,���еݹ�
							{
								OpenMap(&my);//�ݹ�
							}
						}
					}
				}
				My->OffsetY -= 2;//�����ŵ����������꣬����ָ�����ǰ���Ǹ�λ��
			}
			//����ǰ�ľŹ��񶼱������˻ָ����м�λ��
			My->OffsetX -= 1;
			My->OffsetY += 1;
		}
	}
}


