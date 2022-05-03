#pragma once
#include<iostream>
class GameMap
{
public:
	void InitMap(const char* map);
	void RenderMap();
	int(*GetMap())[10]
	{
		return m_Map;
	}
	~GameMap();
private:
	int m_pow, m_col;
	int m_Map[10][10];
};

