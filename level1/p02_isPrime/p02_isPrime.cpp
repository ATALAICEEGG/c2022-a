#include<stdio.h>

int main()
{
	int num=0;
	int a;
	//a�ǳ�����дӢ�ĵ������Լ��������� T-T��	
	int  left;
	printf("������һ������\n");
	scanf("%d",&num);
	a=num-1;
	for(;left!=0&&a>1;a--)
	{
		left=num%a; 
	}
	if(1==a)
	printf("yes\n",num);
	else 
	printf("no\n",num);
	
	return 0;
 } 
