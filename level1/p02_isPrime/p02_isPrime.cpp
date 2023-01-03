#include<stdio.h>

int main()
{
	int num=0;
	int a;
	//a是除数（写英文单词怕自己都看不懂 T-T）	
	int  left;
	printf("请输入一个整数\n");
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
