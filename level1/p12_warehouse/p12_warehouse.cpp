#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>



void check(char name[][100], int quan[],int t);
void input(char name[][100], int quan[], int *t);
void output(char name[][100], int quan[], int *t);


int main(){
	int chs,num=0;
	char n[100][100] = { 0 }, s[100][100] = { 0 };
	int q[100]={0};

	while (1) {


		FILE* fp1 = fopen("C:\\Users\\asus\\Desktop\\�γ�\\��һ��\\�������\\��ҵ\\p12.type.txt", "r+");
		if (fp1 == NULL){
			printf("��ȡʧ��\n");
		}
		FILE* fp2 = fopen("C:\\Users\\asus\\Desktop\\�γ�\\��һ��\\�������\\��ҵ\\p12.type.txt", "r+");
		if (fp2 == NULL){
			printf("��ȡʧ��\n");
		}

		while (fgets(n[num], 99, fp1) && fgets(s[num], 99, fp2)){
			num++;
		}

		//�ټ�һ����sto��charת����int�Ĺ���
		for (int i=0;i<num;i++){
			int p = 0;
			for (int j = 0; s[i][j]; j++){
				p++;
			}
			for (int k = 0; k < p; k++){
				q[i] +=(int)s[i][k];
			}
		}

		printf("��ѡ���ܣ�\n1����ʾ����б�\n2�����\n3������\n4:�˳�����");
		scanf("%d", &chs);
		switch (chs){
		case 1:check(n, q,num); break;
		case 2:input(n, q,&num); break;
		case 3:output(n, q, &num); break;
		case 4:exit(0);
		}
		/*system("cls");*/
		fseek(fp1, 0, SEEK_SET);
		fseek(fp2, 0, SEEK_SET);

		

		for (int i=0;i<num;i++){
			fwrite(n[i],100,sizeof(n[i]),fp1);
			fputc('\n', fp1);
			fwrite(&q[i], 100, sizeof(int), fp1);
			fputc('\n', fp2);
		}
		//����дһ���ļ�
		fclose(fp1);
		fclose(fp2);
	}


	return 0;
}

void check(char name[][100], int quan[], int t){
	int place;
	for (place = 0; place <= t; place++){
		printf("%s				%d", name[place], quan[place]);
	}
}


void input(char name[][100], int quan[],int *t){
	char n1[100] = { 0 };
	int qua,judge=0,place=0;
	printf("�����������ͺţ�����ʮ����ĸ��\n");
	scanf("%s", n1);
	printf("��������������\n");
	scanf("%d", &qua);
	while (place < *t){
		if (strcmp(n1, name[place]) == 0 && place<*t){
			quan[place] += qua;
			judge++;
			break;
		}
		place++;
	}
	if (0 == judge){
		strcpy(name[place+1], n1);
		quan[place+1] = qua;
	}
	
	printf("���\n");
	Sleep(1000);
}

void output(char name[][100], int quan[],int *t){
	//itm st1[200] = { 0 };
	int qua,judge=0,place = 0;
	char n2[100] = { 0 };
	printf("�����������ͺţ�����ʮ����ĸ��\n");
	scanf("%s", n2);
	printf("��������������\n");
	scanf("%d", &qua);
	while (place < *t){
		if (strcmp(n2, name[place]) == 0 && place<*t){
			quan[place] -= qua;
			if (0>quan[place]  ){
				printf("��������,���β���ʧ��\n");
				place--;
			}
			else{
				judge++;
				break;
			}
		}
		place++;
	} 
	if ( 0== judge){
		printf("�������,�����޴˻���\n");
	}
}
 
