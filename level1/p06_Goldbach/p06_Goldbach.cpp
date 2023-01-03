#include<stdio.h>
//啊啊啊之前看错猜想的内容了，抓狂ing 

int main()
{
	int group[100]={2,3};
	int ALL=2;
	int countA=0;
	int countB=0;
	printf("在0~100内证明哥德巴赫猜想\n\n");
	for(int num=3;num<100;num+=2)
	{
		for(countA=0;countA<ALL;countA++)
		{
			if(num%group[countA]==0)
			break;
	

		}
		if (ALL==countA)	{
			group[ALL]=num;
			ALL++;}	

	
	}
	int shu=2;
	
	for(;shu<101;shu+=2)
	{
		for(countA=0;countA<25;countA++)
		{
			int judge=0;
			for(countB=0;judge==0&&countB<25;countB++){
			judge=(shu==group[countA] + group[countB]);
			}
			countB--;
			if(judge!=0){
			printf("%d = %d + %d\n",shu,group[countA],group[countB]);
			break;}
		}
	
	} 
	return 0;
}
