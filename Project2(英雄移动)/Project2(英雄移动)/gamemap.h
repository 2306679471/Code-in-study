#ifndef _GAMEMAP_H_
#define _GAMEMAP_H_
class CGameMap
{
public:
	//��ʼ����ͼ
	void InitMap(int Map[10][10]);
	//��ӡ��ͼ
	void RenderMap();
	//��������ָ��
	int(*GetMap())[10]
	{
		return m_Map;
	}
private:
	int m_Map[10][10]; 
};
#endif