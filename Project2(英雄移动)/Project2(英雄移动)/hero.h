#ifndef _HERO_H
#define _HERO_H_
#include"gamemap.h"
class CHero
{
public:
	//��ʼ��Ӣ������
	void InitHero(CGameMap& GameMap);
	void HeroMove(CGameMap& GameMap);
private:
	int m_PosX;
	int m_PosY;
};
#endif // !_HERO_H
