const int cell = 40;//格子边长
const double range = cell*0.4;//有效点击距离
const int side = 20;//边距
const int row = 15;//几条线（15*15）
const int V = 10;
const long double minv= - 99999999999,maxv=9999999999;
int change = 0;//黑白切换控制数
bool play = false;
int chessx = 0, chessy = 0;
int num;//回合数
struct record {
	int place;          //位置的状态    玩家-1,   空位置0,   电脑1
	long double  value;        //该点价值分
	long double totalvalue;        //下一步棋下这点时棋盘的总优势分	

};
