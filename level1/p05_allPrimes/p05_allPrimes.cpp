#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
	clock_t begin, end;
	double cost;
	begin = clock();
	
	int group[500]={2,3};
	int ALL=2;
	int a=0;

	for(int x=3;x<1000;x+=2)
	{
		for(a=0;a<ALL;a++)
		{
			if(x%group[a]==0)
			break;
	
	
		}
		if (ALL==a)	{
			group[ALL]=x;
			ALL++;}	
		
		
	}
	for(a=0;a<ALL;a++)	
		printf("%d   ",group[a]);
	
	end = clock();
	cost = (double)((end - begin)/CLOCKS_PER_SEC);
	printf("\n ÓÃÊ±£¨Ãë£©: %lf secs",cost);

return 0;
}
