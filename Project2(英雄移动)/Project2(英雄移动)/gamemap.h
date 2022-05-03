#ifndef _GAMEMAP_H_
#define _GAMEMAP_H_
class CGameMap
{
public:
	//初始化地图
	void InitMap(int Map[10][10]);
	//打印地图
	void RenderMap();
	//返回数组指针
	int(*GetMap())[10]
	{
		return m_Map;
	}
private:
	int m_Map[10][10]; 
};
#endif