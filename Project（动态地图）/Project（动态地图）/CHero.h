#ifndef _HERO_H
#define _HERO_H_
#include"GameMap.h"
class CHero
{
public:
	//��ʼ��Ӣ������
	void InitHero(GameMap& GameMap);
	void HeroMove(GameMap& GameMap);
private:

	int m_PosX;
	int m_PosY;
};
#endif // !_HERO_H
