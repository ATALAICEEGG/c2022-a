#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

const int xtop = 9, ytop = 7;
char putin;
void move(char a);
int x = 1, y = 0, x0 = 9, y0 = 6, judge = 0, f = 0;
void drawmap();
char map[20][20] = { "#A########",
"# #    #+#",
"#   ##   #",
"## # 0# E#",
"#  #     #",
"# ######E#",
"#  E  +#+#",
"##########", };
int event(int a, int b);

int main(){

	drawmap();
	while (x != x0 || y != y0){
		putin = _getche();
		move(putin);
		printf("�����%d/3\n", f);
		int j = event(x, y);
		if (j == 1)
			break;


	}
	return 0;
}



void drawmap(){
	printf("\nw:��\t"); printf("s:��\n"); printf("a:��\t"); printf("d:��\n\n");
	while (1){
		for (int i = 0; i < ytop + 1; i++){
			puts(map[i]);
		}
		break;
	}
}




int event(int a, int b){
	if (a == 5 && b == 3){
		if (judge == 0){
			printf("��ϲ�㷢���˱��ء����𵰣�����\n");
			Sleep(3000);
			system("cls");
			drawmap();
			judge++;
		}
		else if (judge == 1)
		{
			printf("�����Ѿ�û�н���...\n");
			Sleep(1000);
			system("cls");
			drawmap();
			judge++;
		}
	}
	if (f == 3){
		printf("���سɹ���ף���㣡");
		Sleep(3000);
		return 1;
	}
	return 0;
}





void move(char a){
	if (a == 'w'){
		if (y == 0)		printf("���߽���Ŷ\n");
		else if (map[y - 1][x] == ' ' || map[y - 1][x] == '0'){
			map[y][x] = ' ';
			y--;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else if (map[y - 1][x] == 'E'&&map[y - 2][x] == ' '){
			map[y][x] = ' ';
			y--;
			map[y][x] = 'A';
			map[y - 1][x] = 'E';
			system("cls");
			drawmap();
		}
		else if (map[y - 1][x] == 'E'&&map[y - 2][x] == '+'){
			f++;
			map[y][x] = ' ';
			y--;
			map[y][x] = 'A';
			map[y - 1][x] = 'E';
			system("cls");
			drawmap();
		}

		else  {
			system("cls");
			drawmap();
			printf("��·��ͨ\n");
		}
	}


	else if (a == 's'){
		if (y == ytop)		printf("���߽���Ŷ\n");
		else if (map[y + 1][x] == ' ' || map[y + 1][x] == '0'){
			map[y][x] = ' ';
			y++;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else if (map[y + 1][x] == 'E'&&map[y + 2][x] == ' '){
			map[y][x] = ' ';
			y++;
			map[y][x] = 'A';
			map[y + 1][x] = 'E';
			system("cls");
			drawmap();
		}
		else if (map[y + 1][x] == 'E'&&map[y + 2][x] == '+'){
			f++;
			map[y][x] = ' ';
			y++;
			map[y][x] = 'A';
			map[y + 1][x] = 'E';
			system("cls");
			drawmap();
		}
		else  {
			system("cls");
			drawmap();
			printf("��·��ͨ\n");
		}
	}


	else if (a == 'a'){
		if (x == 0)		printf("���߽���Ŷ\n");
		else if (map[y][x - 1] == ' ' || map[y][x - 1] == '0'){
			map[y][x] = ' ';
			x--;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else if (map[y][x - 1] == 'E'&&map[y][x - 2] == ' '){
			map[y][x] = ' ';
			x--;
			map[y][x] = 'A';
			map[y][x - 1] = 'E';
			system("cls");
			drawmap();
		}
		else if (map[y][x - 1] == 'E'&&map[y][x - 2] == '+'){
			f++;
			map[y][x] = ' ';
			x--;
			map[y][x] = 'A';
			map[y][x - 1] = 'E';
			system("cls");
			drawmap();
		}
		else {
			system("cls");
			drawmap();
			printf("��·��ͨ\n");
		}
	}


	else if (a == 'd'){
		if (x == xtop)		printf("���߽���Ŷ\n");
		else if (map[y][x + 1] == ' ' || map[y][x + 1] == '0'){
			map[y][x] = ' ';
			x++;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else if (map[y][x + 1] == 'E'&&map[y][x + 2] == ' '){
			map[y][x] = ' ';
			x++;
			map[y][x] = 'A';
			map[y][x + 1] = 'E';
			system("cls");
			drawmap();
		}
		else if (map[y][x + 1] == 'E'&&map[y][x + 2] == '+'){
			f++;
			map[y][x] = ' ';
			x++;
			map[y][x] = 'A';
			map[y][x + 1] = 'E';
			system("cls");
			drawmap();
		}
		else {
			system("cls");
			drawmap();
			printf("��·��ͨ\n");
		}
	}
}
