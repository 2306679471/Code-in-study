struct My
{
	//玩家坐标
	int TopX;
	int TopY;

	int n;//游戏开始界面的选项

	int la;//雷的数量
	int row;//地图的行
	int col;//地图的列

	//地图展开偏移量
	int OffsetX;
	int OffsetY;
	//地图
	int **PGameMap;

};
//游戏开始界面
int GameBegin(My *my);

//初始化地图
void DefinMap(My *my);

//布雷
void UpLand(My *my);

//计算周围雷的数量
void CalLand(My *my);

//打印地图
void PrintMap(My *my);

//按键响应
void KeyControl(My *my);

//选中周围0地雷展开
void OpenMap(My *my);

//胜利与失败判断
int VictoryC(My *my);



















