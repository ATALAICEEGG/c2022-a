#include<stdio.h>
#include	<graphics.h>
#include	<conio.h>
#include	<stdlib.h>
#include<math.h>
#include	"data.h"
#include<mmsystem.h>
#include<time.h>
#pragma comment(lib, "winmm.lib")
#define _CRT_SECURE_NO_WARNINGS

IMAGE gImage, img;
MOUSEMSG msg = { 0 };

void drawmap();//画棋盘
void search(MOUSEMSG msg, struct record p[15][15]);
int AIgo(struct record p[15][15]);//AI下棋
int judge(struct record p[15][15]);//判断是否输赢
void FINAL(int a);//结束显示
void init(struct record p[15][15]);//初始化

void chessdown(int i, int a, int b, struct record p[15][15]);
long double assess(struct record p[15][15]);
void p_assess(struct record p[15][15]);
void start(struct record p[15][15]);
long double calculation(struct record p[15][15], int turn, int times, long double a, long double b);


int main(){
	struct record p[15][15];
	start(p);
	
	return 0;
}




int AIgo(struct record p[15][15]){
	int t, m, n;
	int  r=7, l=7;//r,l用于记录最佳落棋位置
	long double v = minv;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			
			if (p[i][j].place == 0){
				t = 0;
				for (m = -1; m < 2; m++) {
					for (n = -1; n < 2; n++) {
						if (p[i + m][j + n].place != 0) {
							t++;     //偏僻点剪枝
						}
					}
				}
				if (t != 0){
					p[i][j].place = 1;
					if (judge(p) == 1){

						chessdown(1, i, j,p);
						return 0;
					}
					p[i][j].totalvalue = calculation(p, 1, 2, minv, maxv);
					p[i][j].place = 0;
					if (v < p[i][j].totalvalue)	{
						v = p[i][j].totalvalue;
						r = i, l = j;
					}
				}
			}
		}
	}
	chessdown(1,r, l,p);
	return 0;
}


long double calculation(struct record p[15][15], int turn, int times,long double a,long double b){
	long double v = 0;
	int i, j,t=0,left=0;
	if (judge(p)>0||times == 0){
		return assess(p);
	}
	else if (turn == 1){                 //AI
		for (i = 0; i < row; i++){
			if (left==1)
			{
				break;
			}
			for (j = 0; j < row; j++){
				if (p[i][j].place == 0){

					if (num < 50){
						t = 0;
						for (int m = -1; m < 2; m++) {
							for (int n = -1; n < 2; n++) {
								if (p[m + i][n + j].place != 0) {
									t++;
								}

							}
						}

					}
					else     t = 1;

					if (t == 0){
						v = minv;
					}
					else{
						p[i][j].place = 1;   
						v = calculation(p, (turn + 1) % 2, times - 1, a, b);
						p[i][j].place = 0;
					}

					if (a < v){//找最大值
						a = v;
					}
					if (b < a){
						break;
						left = 1;
					}
				}
			}
		}
		return a;
	}
	else if (turn == 0){             //玩家
		for (i = 0; i < row; i++){
			if (left == 1){
				break;
			}
			for (j = 0; j < row; j++){
				if (p[i][j].place == 0){
					if (num < 50){
						t = 0;
						for (int m = -1; m < 2; m++) {
							for (int n = -1; n < 2; n++) {
								if (p[m + i][n + j].place != 0) {
									t++;
								}
							}
						}
					}
					else    t = 1;
				
					if (t == 0){
						v = maxv;
					}
					else{
						p[i][j].place = -1;  
						v = calculation(p, (turn + 1) % 2, times - 1, a, b);
						p[i][j].place = 0;     
					}

					if (b > v){//找最小值
					
						b = v;
					}
					if (b < a)
					{
						left= 1;
						break;
					}
				}
			}
		}
		return b;
	}
	return 0;
}



void chessdown(int i, int a, int b, struct record p[15][15]){
	int x = side + (b * (cell));
	int y = side + (a * (cell));
	if (i == -1){
		setfillcolor(BLACK);
		p[a][b].place = -1;
		solidcircle(x, y, 20);
	
	}
	else if(i==1){
		setfillcolor(WHITE);
		p[a][b].place = 1;
		solidcircle(x, y, 20);
	}
	else   printf("程序错误\n");
}





//1
void drawmap(){
	loadimage(&gImage, _T("棋盘2.jpg"), 640, 640);
	initgraph(600, 600);

	settextcolor(YELLOW);
	putimage(0, 0, &gImage);
	outtextxy(250, 5, L"简易五子棋");

	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);
	for (int a = 0; a < 15; a++){
		line(side, side + (a * (cell)), 580, side + a * (cell));
	}
	for (int b = 0; b < 15; b++){
		line(side + b * (cell), side, side + b * (cell), 580);
	}
	fillcircle(4 * cell - cell / 2, 4 * cell - cell / 2, 3);
	fillcircle(12 * cell - cell / 2, 4 * cell - cell / 2, 3);
	fillcircle(8 * cell - cell / 2, 8 * cell - cell / 2, 3);
	fillcircle(12 * cell - cell / 2, 12 * cell - cell / 2, 3);
	fillcircle(4 * cell - cell / 2, 12 * cell - cell / 2, 3);
}




void FINAL(int a){
	
	if (a >0){
		settextstyle(42, 20, _T("隶书"));
		setbkmode(TRANSPARENT);
		if (a==2){
			outtextxy(200, 250, _T("黑方胜利"));

		}

		else if(a==1){
			outtextxy(200, 250, _T("白方胜利"));
		}
		setfillcolor(BLUE);
		fillrectangle(80, 390, 280, 450);
		fillrectangle(380, 390, 480, 450);
		outtextxy(100, 400, _T("重新开始"));
		outtextxy(400, 400, _T("退出"));

		while (1)
		{
			MOUSEMSG n;//鼠标信息
			n = GetMouseMsg();
			switch (n.uMsg) {
			case WM_LBUTTONDOWN:
				if (n.x <= 280 && n.x >= 100 && n.y <= 450 && n.y >= 390){
					struct record pp[15][15];
					start(pp);   //返回游戏界面
				}

				if (n.x <= 480 && n.x >= 380 && n.y <= 450 && n.y >= 390)
				{
					/*_getch();*/
					closegraph(); // 关闭绘图窗口
					exit(0);    //强制退出
				}
			}
		}
	}
	
}




int judge(struct record p[15][15]){
	int m, n;
	for (m = 0;m < row; m++){
		for (n = 0; n < row; n++){
			for (int i = 0; i < 5; i++)//往左5个，往右匹配4个子，20种情况
			{
				if (n - i >= 0 && n - i + 4 < row &&
					p[m][n - i].place == p[m][n - i + 1].place &&
					p[m][n - i].place == p[m][n - i + 2].place &&
					p[m][n - i].place == p[m][n - i + 3].place &&
					p[m][n - i].place == p[m][n - i + 4].place){
					if (p[m][n - i].place == -1)    return 2;
					else if (p[m][n - i].place == 1)    return 1;
				}

			}

			for (int i = 0; i < 5; i++)//竖直方向(上下延伸4个)for (int i = 0; i < 5; i++)(
			{
				if (m - i >= 0 && m - i + 4 < row &&
					p[m - i][n].place == p[m - i + 1][n].place &&
					p[m - i][n].place == p[m - i + 2][n].place &&
					p[m - i][n].place == p[m - i + 3][n].place &&
					p[m - i][n].place == p[m - i + 4][n].place){
					if (p[m - i][n].place == -1)    return 2;
					else if (p[m - i][n].place == 1)   return 1;
				}

			}

			for (int i = 0; i < 5; i++)//第[m+i]行，第[n-i]的棋子，与右上方连续4个棋子都相同
			{
				if (m + i < row  &&		m + i - 4 >= 0 && n - i >= 0 && n - i + 4 < row &&
					p[m + i][n - i].place == p[m + i - 1][n - i + 1].place &&
					p[m + i][n - i].place == p[m + i - 2][n - i + 2].place &&
					p[m + i][n - i].place == p[m + i - 3][n - i + 3].place &&
					p[m + i][n - i].place == p[m + i - 4][n - i + 4].place){
					if (p[m + i][n - i].place == -1)    return 2;
					else if (p[m + i][n - i].place == 1)   return 1;
				}
			}

			for (int i = 0; i < 5; i++)//第[m+i]行，第[n-i]的棋子，与右上方连续4个棋子都相同
			{
				if (m - i + 4 < row &&		m - i >= 0 && n - i >= 0 && n - i + 4 < row &&
					p[m - i][n - i].place == p[m - i + 1][n - i + 1].place &&
					p[m - i][n - i].place == p[m - i + 2][n - i + 2].place &&
					p[m - i][n - i].place == p[m - i + 3][n - i + 3].place &&
					p[m - i][n - i].place == p[m - i + 4][n - i + 4].place){
					if (p[m - i][n - i].place == -1)    return 2;
					else if (p[m - i][n - i].place == 1)  return 1;
				}
			}
		}
	}


	return 0;
}





void init(struct record p[15][15]){
	change = 0;//黑白切换控制数
	play = false;
	chessx = 0, chessy = 0;
	num = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++){
			p[i][j].place = 0;
			p[i][j].value = 0;
			p[i][j].totalvalue = 0;
		}

	}
}



long double assess(struct record p[15][15])
{
	int i, j;
	p_assess(p);     //某点价值评定
	long double sum = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			sum += p[i][j].value;//棋盘总优势分为所有点分数的和
		}
	}
	return sum;
}

void p_assess(struct record p[15][15]){
	int i, j, k, m, n, x, y;
	for (i = 0; i < row; i++)   
	{
		for (j = 0; j < row; j++)
		{
			if (p[i][j].place == 0)
			{
				p[i][j].value = 0;      //空位价值为零 
			}
			else  
			{   
				long double v1 = V, v2 = V, v3 = V, v4 = V, v5 = V, v6 = V, v7 = V, v8 = V;

				for (x = 0, n = j; p[i][j].place != -p[i][n + 1].place && n + 1 < 15 && x < 4;x++, n++)       //右
				{
				}
				if (x < 4)
				{
					v1 = 0; 
				}
				else {
					for (k = 0, n = j; p[i][j].place == p[i][n + 1].place && k < 5; k++, n++)       //右
					{
						v1 *= V;
					}
				}
				for (y = 0, n = j; p[i][j].place != -p[i][n - 1].place && n > 0 && y < 4; y++, n--)      //左
				{
				}
				if (y < 4){
					v2 = 0; 
				}
				else {
					for (k = 0, n = j; p[i][j].place == p[i][n - 1].place && k < 5; k++, n--)      //左
					{
						v2 *= V;  
					}
				}

				for (x = 0, n = i; p[i][j].place != -p[n + 1][j].place && n + 1 < 15 && x < 5; x++, n++)       //上
				{
				}
				if (x < 4){
					v3 = 0; 
				}
				else {
					for (k = 0, n = i; p[i][j].place == p[n + 1][j].place && k < 5; k++, n++)       //上
					{
						v3 *= V; 
					}
				}
				for (y = 0, n = i; p[i][j].place != -p[n - 1][j].place && n > 0 && y < 5; y++, n--)       //下
				{
				}
				if (y < 4){
					v4 = 0;   
				}
				else {
					for (k = 0, n = i; p[i][j].place == p[n - 1][j].place && k < 5; k++, n--)       //下
					{
						v4 *= V; 
					}
				}
				for (x = 0, m = i, n = j; p[i][j].place != -p[m - 1][n + 1].place && n + 1 < 15 && m >5 && x < 5; x++, m--, n++) //右上
				{
				}
				if (x < 4){
					v5 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m - 1][n + 1].place && k < 5; k++, m--, n++)       //右上
					{
						v5 *= V;
					}
				}
				for (y = 0, m = i, n = j; p[i][j].place != -p[m + 1][n - 1].place && m + 1 < 15 && n > 0 && y < 5; y++, m++, n--) //左下
				{
				}
				if (y < 4)
				{
					v6 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m + 1][n - 1].place && k < 5; k++, m++, n--)       //左下
					{
						v6 *= V; 
					}
				}
				for (x = 0, m = i, n = j; p[i][j].place != -p[m - 1][n - 1].place && n > 5 && m >5 && x < 5; x++, m--, n--)  //左上
				{
				}
				if (x < 4)
				{
					v7 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m - 1][n - 1].place && k < 5; k++, m--, n--)       //左上
					{
						v7 *= V;
					}
				}
				for (y = 0, m = i, n = j; p[i][j].place != -p[m + 1][n + 1].place && n + 1 < 15 && m + 1 < 15 && y < 5; y++, m++, n++) //右下
				{
				}
				if (y < 4)
				{
					v8 = 0;  
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m + 1][n + 1].place && k < 5; k++, m++, n++)       //右下
					{
						v8 *= V; 
					}
				}
				p[i][j].value = v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8 + 0.5 * (15 - abs(i - 7) - abs(j - 7));  
				if (p[i][j].place == -1)   
				{
					p[i][j].value = -p[i][j].value * 10;    
				}
			}
		}
	}
}



void start(struct record p[15][15]){
	init(p);
	drawmap();
	while (1){
		msg = GetMouseMsg();
	
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			search(msg,p);
			if (play != true)		continue;
			int pass = judge(p);
			FINAL(pass);

			AIgo(p);
			pass = judge(p);
			FINAL(pass);
			num++;
		}

	}
}



void search(MOUSEMSG msg, struct record p[15][15]){//把棋子下到格子上

	int x, y, r0, l0;
	l0 = msg.x / cell;/*算出棋子下在的左上角点第几列*/
	x = l0*cell + side;
	r0 = msg.y / cell;/*算出棋子下在的左上角点第几行*/
	y = r0*cell + side;

	chessx = x;
	chessy = y;
	if (p[l0][r0].place == 0){//确认原地点无棋子-》下棋成功？

		play = true;
		chessdown(-1,r0,l0,p);

	}
	else
		play = false;

}