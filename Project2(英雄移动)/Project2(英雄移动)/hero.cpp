#include "Hero.h"
#include <conio.h>
#include <windows.h>
void CHero::InitHero(CGameMap& GameMap)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (2 == GameMap.GetMap()[i][j])
			{
				m_PosX = i, m_PosY = j;
				return;
			}
		}
	}
}
void CHero::HeroMove(CGameMap& GameMap)
{
	int Input = _getch();
	system("CLS");
	switch (Input)
	{
	case 's':
	case 'S':
		if (0 == GameMap.GetMap()[m_PosX + 1][m_PosY])
		{
			GameMap.GetMap()[m_PosX + 1][m_PosY] += 2;
			GameMap.GetMap()[m_PosX][m_PosY] -= 2;
			++m_PosX;
		}
		break;
	case 'w':
	case 'W':
		if (0 == GameMap.GetMap()[m_PosX - 1][m_PosY])
		{
			GameMap.GetMap()[m_PosX - 1][m_PosY] += 2;
			GameMap.GetMap()[m_PosX][m_PosY] -= 2;
			--m_PosX;
		}
		break;
	case 'a':
	case 'A':
		if (0 == GameMap.GetMap()[m_PosX][m_PosY-1])
		{
			GameMap.GetMap()[m_PosX][m_PosY - 1] += 2;
			GameMap.GetMap()[m_PosX][m_PosY] -= 2;
			--m_PosY;
		}
		break;
	case 'd':
	case 'D':
		if (0 == GameMap.GetMap()[m_PosX][m_PosY + 1])
		{
			GameMap.GetMap()[m_PosX][m_PosY + 1] += 2;
			GameMap.GetMap()[m_PosX][m_PosY] -= 2;
			++m_PosY;
		}
		break;
	default:
		break;
	}

}