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

void drawmap();//������
void search(MOUSEMSG msg, struct record p[15][15]);
int AIgo(struct record p[15][15]);//AI����
int judge(struct record p[15][15]);//�ж��Ƿ���Ӯ
void FINAL(int a);//������ʾ
void init(struct record p[15][15]);//��ʼ��

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
	int  r=7, l=7;//r,l���ڼ�¼�������λ��
	long double v = minv;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			
			if (p[i][j].place == 0){
				t = 0;
				for (m = -1; m < 2; m++) {
					for (n = -1; n < 2; n++) {
						if (p[i + m][j + n].place != 0) {
							t++;     //ƫƧ���֦
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

					if (a < v){//�����ֵ
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
	else if (turn == 0){             //���
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

					if (b > v){//����Сֵ
					
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
	else   printf("�������\n");
}





//1
void drawmap(){
	loadimage(&gImage, _T("����2.jpg"), 640, 640);
	initgraph(600, 600);

	settextcolor(YELLOW);
	putimage(0, 0, &gImage);
	outtextxy(250, 5, L"����������");

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
		settextstyle(42, 20, _T("����"));
		setbkmode(TRANSPARENT);
		if (a==2){
			outtextxy(200, 250, _T("�ڷ�ʤ��"));

		}

		else if(a==1){
			outtextxy(200, 250, _T("�׷�ʤ��"));
		}
		setfillcolor(BLUE);
		fillrectangle(80, 390, 280, 450);
		fillrectangle(380, 390, 480, 450);
		outtextxy(100, 400, _T("���¿�ʼ"));
		outtextxy(400, 400, _T("�˳�"));

		while (1)
		{
			MOUSEMSG n;//�����Ϣ
			n = GetMouseMsg();
			switch (n.uMsg) {
			case WM_LBUTTONDOWN:
				if (n.x <= 280 && n.x >= 100 && n.y <= 450 && n.y >= 390){
					struct record pp[15][15];
					start(pp);   //������Ϸ����
				}

				if (n.x <= 480 && n.x >= 380 && n.y <= 450 && n.y >= 390)
				{
					/*_getch();*/
					closegraph(); // �رջ�ͼ����
					exit(0);    //ǿ���˳�
				}
			}
		}
	}
	
}




int judge(struct record p[15][15]){
	int m, n;
	for (m = 0;m < row; m++){
		for (n = 0; n < row; n++){
			for (int i = 0; i < 5; i++)//����5��������ƥ��4���ӣ�20�����
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

			for (int i = 0; i < 5; i++)//��ֱ����(��������4��)for (int i = 0; i < 5; i++)(
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

			for (int i = 0; i < 5; i++)//��[m+i]�У���[n-i]�����ӣ������Ϸ�����4�����Ӷ���ͬ
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

			for (int i = 0; i < 5; i++)//��[m+i]�У���[n-i]�����ӣ������Ϸ�����4�����Ӷ���ͬ
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
	change = 0;//�ڰ��л�������
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
	p_assess(p);     //ĳ���ֵ����
	long double sum = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			sum += p[i][j].value;//���������Ʒ�Ϊ���е�����ĺ�
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
				p[i][j].value = 0;      //��λ��ֵΪ�� 
			}
			else  
			{   
				long double v1 = V, v2 = V, v3 = V, v4 = V, v5 = V, v6 = V, v7 = V, v8 = V;

				for (x = 0, n = j; p[i][j].place != -p[i][n + 1].place && n + 1 < 15 && x < 4;x++, n++)       //��
				{
				}
				if (x < 4)
				{
					v1 = 0; 
				}
				else {
					for (k = 0, n = j; p[i][j].place == p[i][n + 1].place && k < 5; k++, n++)       //��
					{
						v1 *= V;
					}
				}
				for (y = 0, n = j; p[i][j].place != -p[i][n - 1].place && n > 0 && y < 4; y++, n--)      //��
				{
				}
				if (y < 4){
					v2 = 0; 
				}
				else {
					for (k = 0, n = j; p[i][j].place == p[i][n - 1].place && k < 5; k++, n--)      //��
					{
						v2 *= V;  
					}
				}

				for (x = 0, n = i; p[i][j].place != -p[n + 1][j].place && n + 1 < 15 && x < 5; x++, n++)       //��
				{
				}
				if (x < 4){
					v3 = 0; 
				}
				else {
					for (k = 0, n = i; p[i][j].place == p[n + 1][j].place && k < 5; k++, n++)       //��
					{
						v3 *= V; 
					}
				}
				for (y = 0, n = i; p[i][j].place != -p[n - 1][j].place && n > 0 && y < 5; y++, n--)       //��
				{
				}
				if (y < 4){
					v4 = 0;   
				}
				else {
					for (k = 0, n = i; p[i][j].place == p[n - 1][j].place && k < 5; k++, n--)       //��
					{
						v4 *= V; 
					}
				}
				for (x = 0, m = i, n = j; p[i][j].place != -p[m - 1][n + 1].place && n + 1 < 15 && m >5 && x < 5; x++, m--, n++) //����
				{
				}
				if (x < 4){
					v5 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m - 1][n + 1].place && k < 5; k++, m--, n++)       //����
					{
						v5 *= V;
					}
				}
				for (y = 0, m = i, n = j; p[i][j].place != -p[m + 1][n - 1].place && m + 1 < 15 && n > 0 && y < 5; y++, m++, n--) //����
				{
				}
				if (y < 4)
				{
					v6 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m + 1][n - 1].place && k < 5; k++, m++, n--)       //����
					{
						v6 *= V; 
					}
				}
				for (x = 0, m = i, n = j; p[i][j].place != -p[m - 1][n - 1].place && n > 5 && m >5 && x < 5; x++, m--, n--)  //����
				{
				}
				if (x < 4)
				{
					v7 = 0; 
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m - 1][n - 1].place && k < 5; k++, m--, n--)       //����
					{
						v7 *= V;
					}
				}
				for (y = 0, m = i, n = j; p[i][j].place != -p[m + 1][n + 1].place && n + 1 < 15 && m + 1 < 15 && y < 5; y++, m++, n++) //����
				{
				}
				if (y < 4)
				{
					v8 = 0;  
				}
				else {
					for (k = 0, m = i, n = j; p[i][j].place == p[m + 1][n + 1].place && k < 5; k++, m++, n++)       //����
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



void search(MOUSEMSG msg, struct record p[15][15]){//�������µ�������

	int x, y, r0, l0;
	l0 = msg.x / cell;/*����������ڵ����Ͻǵ�ڼ���*/
	x = l0*cell + side;
	r0 = msg.y / cell;/*����������ڵ����Ͻǵ�ڼ���*/
	y = r0*cell + side;

	chessx = x;
	chessy = y;
	if (p[l0][r0].place == 0){//ȷ��ԭ�ص�������-������ɹ���

		play = true;
		chessdown(-1,r0,l0,p);

	}
	else
		play = false;

}