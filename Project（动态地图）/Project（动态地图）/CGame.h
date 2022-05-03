#ifndef _GAME_H_
#define _GAME_H_
#include"CHero.h"
class Cgame
{
public:
	void InitGame(const char* p);
	void GameStar(const char *p);
private:
	CHero* h;
	GameMap* gm;

};
#endif
