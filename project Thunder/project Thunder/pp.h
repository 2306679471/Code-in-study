struct My
{
	//�������
	int TopX;
	int TopY;

	int n;//��Ϸ��ʼ�����ѡ��

	int la;//�׵�����
	int row;//��ͼ����
	int col;//��ͼ����

	//��ͼչ��ƫ����
	int OffsetX;
	int OffsetY;
	//��ͼ
	int **PGameMap;

};
//��Ϸ��ʼ����
int GameBegin(My *my);

//��ʼ����ͼ
void DefinMap(My *my);

//����
void UpLand(My *my);

//������Χ�׵�����
void CalLand(My *my);

//��ӡ��ͼ
void PrintMap(My *my);

//������Ӧ
void KeyControl(My *my);

//ѡ����Χ0����չ��
void OpenMap(My *my);

//ʤ����ʧ���ж�
int VictoryC(My *my);



















