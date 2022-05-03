#include "GameMap.h"
#include <iostream>
using namespace std;
void CGameMap::InitMap(int Map[10][10])
{
	memcpy(m_Map, Map, sizeof(int) * 10 * 10);
}
void CGameMap::RenderMap()
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
				cout << "бЎ";
				break;
			case 2:
				cout << "бс";
				break;
			}

		}
		cout << endl;
	}

}