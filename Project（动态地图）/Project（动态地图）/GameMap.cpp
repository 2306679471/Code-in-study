#include "GameMap.h"
#include<iostream>
using namespace std;
void GameMap::InitMap(const char *p)//ÎÄ¼þÂ·¾¶
{
	FILE* pfile = fopen(p, "rb");
	fread(&m_pow, sizeof(int), 1, pfile);
	fread(&m_col, sizeof(int), 1, pfile);
	fread(m_Map, sizeof(int), 100, pfile);
	fclose(pfile);
	int** pp;
	pp = new  int* [10];
	for (int i = 0; i < 10; i++)
	{
		pp[i] = new int[10];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pp[i][j] =GetMap()[i][j];
		}
	}
}
void GameMap::RenderMap()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (m_Map[i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "¡ö";
				break;
			case 2:
				cout << "¡á";
				break;
			}

		}
		cout << endl;
	}

}
GameMap::~GameMap()
{
	delete m_Map;
}