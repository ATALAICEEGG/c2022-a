const int cell = 40;//���ӱ߳�
const double range = cell*0.4;//��Ч�������
const int side = 20;//�߾�
const int row = 15;//�����ߣ�15*15��
const int V = 10;
const int minv= - 99999999,maxv=99999999;
int change = 0;//�ڰ��л�������
bool play = false;
int chessr = 0, chessl = 0, chessx = 0, chessy = 0;
struct record {
	int place;          //λ�õ�״̬    ���-1,   ��λ��0,   ����1
	double  value;        //�õ��ֵ��
	int totalvalue;        //��һ���������ʱ���̵������Ʒ�	

};
