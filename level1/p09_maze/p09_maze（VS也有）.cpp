#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

const int xtop=9,ytop=7;
char putin;
void move(char a);
int x = 1, y = 0, x0 = 9, y0 = 6, judge = 0, f = 0;
void drawmap();
char map[20][20] = { "#A########",
										"# #    # #",
										"#   ##   #",
										"## # 0## #",
										"#  #     #",
										"# ###### #",
										"#      #  ",
										"##########",};
void event(int a, int b);

int main(){

	drawmap();
	while (x != x0||y != y0){
		putin = _getche();
		move(putin);
		event(x, y);
		if (f!=0)
			break;
	

	}
	return 0;
}



void drawmap(){
	printf("\nw:��\t"); printf("s:��\n"); printf("a:��\t"); printf("d:��\n\n");
	while (1){
		for (int i = 0; i < ytop+1; i++){
			puts(map[i]);
		}
		break;
	}
}




void event(int a, int b){
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
	if (a == x0&&b == y0){
		printf("���سɹ���ף���㣡");
		f++;
		Sleep(3000);
	}
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
		else  printf("��·��ͨ\n");
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
		else  printf("��·��ͨ\n");
	}
	
	else if (a == 'a'){
		if (x == 0)		printf("���߽���Ŷ\n");
		else if (map[y][x - 1] == ' '||map[y][x-1] == '0'){
			map[y][x] = ' ';
			x--;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else  printf("��·��ͨ\n");
	}
	else if (a == 'd'){
		if (x == xtop)		printf("���߽���Ŷ\n");
		else if (map[y][x + 1] == ' '||map[y][x+1] == '0'){
			map[y][x] = ' ';
			x++;
			map[y][x] = 'A';
			system("cls");
			drawmap();
		}
		else  printf("��·��ͨ\n");
	}
}
