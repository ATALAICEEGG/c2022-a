const int cell = 40;//���ӱ߳�
const double range = cell*0.4;//��Ч�������
const int side = 20;//�߾�
const int row = 15;//�����ߣ�15*15��
const int V = 10;
const long double minv= - 99999999999,maxv=9999999999;
int change = 0;//�ڰ��л�������
bool play = false;
int chessx = 0, chessy = 0;
int num;//�غ���
struct record {
	int place;          //λ�õ�״̬    ���-1,   ��λ��0,   ����1
	long double  value;        //�õ��ֵ��
	long double totalvalue;        //��һ���������ʱ���̵������Ʒ�	

};
