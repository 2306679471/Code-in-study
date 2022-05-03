#include<iostream>
#include"CGame.h"
using namespace std;
int main()
{
	//int pow,col;
	/*int Map[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};*/
	
	Cgame Game;
	Game.GameStar("1.map");
	/*FILE* Pfile=fopen("1.map", "wb");
	fwrite(&pow, sizeof(int), 1, Pfile);
	fwrite(&col, sizeof(int), 1, Pfile);
	fwrite(Map, sizeof(Map), 1, Pfile);
	fclose(Pfile);
	FILE* pfile = fopen("1.map", "rb");
	fread(&pow, sizeof(int), 1, pfile);
	fread(&col, sizeof(int), 1, pfile);
	
	fclose(pfile);*/
	return 0;
}	