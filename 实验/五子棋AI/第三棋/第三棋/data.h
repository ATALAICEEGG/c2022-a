const int cell = 40;//格子边长
const double range = cell*0.4;//有效点击距离
const int side = 20;//边距
const int row = 15;//几条线（15*15）
const int V = 10;
const int minv= - 99999999,maxv=99999999;
int change = 0;//黑白切换控制数
bool play = false;
int chessr = 0, chessl = 0, chessx = 0, chessy = 0;
struct record {
	int place;          //位置的状态    玩家-1,   空位置0,   电脑1
	double  value;        //该点价值分
	int totalvalue;        //下一步棋下这点时棋盘的总优势分	

};
