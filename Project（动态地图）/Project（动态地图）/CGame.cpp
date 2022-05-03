#include"CGame.h"
void Cgame::InitGame(const char *p)
{
	gm = new GameMap;
	h = new CHero;
	
	gm->InitMap(p);
	h->InitHero(*gm);
}//
void Cgame::GameStar(const char *p)
{
	InitGame(p);
	while (1)
	{
		gm->RenderMap();
		h->HeroMove(*gm);
	}
	
}