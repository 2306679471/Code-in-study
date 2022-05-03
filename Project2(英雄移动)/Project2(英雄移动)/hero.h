#ifndef _HERO_H
#define _HERO_H_
#include"gamemap.h"
class CHero
{
public:
	//初始化英雄数据
	void InitHero(CGameMap& GameMap);
	void HeroMove(CGameMap& GameMap);
private:
	int m_PosX;
	int m_PosY;
};
#endif // !_HERO_H
