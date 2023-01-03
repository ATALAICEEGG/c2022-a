#include<stdio.h>
int POW(int a)
{
	int b=a*a*a;
	return b;
}
int main()
{
	int num=100;
	int HUNDRED,TEN,DIGIT;
	//	未去0 
	int H,T;
	//	分别为十位个位 
	for(;num<999;num++)
	{
		HUNDRED=num-(num%100);
		H=HUNDRED/100;
		TEN=(num%100)-(num%100)%10;
		T=TEN/10;
		DIGIT=num%10;
		int test=0;
		//test:水仙计算中间数 
		test=(num==POW(H)+POW(T)+POW(DIGIT));
		if(0!=test)
		printf("%d\n",num);
	}
	return 0;
 } 
