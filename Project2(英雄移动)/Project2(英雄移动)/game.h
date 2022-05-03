#ifndef _GAME_H_
#define _GAME_H_
#include"hero.h"
class Cgame
{
public:
	void InitGame();
	void GameStar();
private:
	CHero* h;
	CGameMap* gm;
	
};
#endif
