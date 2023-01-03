#include<stdio.h>

int main()
{
	int age=1;
	int b=0;
	int c=0;
	for(age=1;0==c;age++)
	{
		for(;0==b;age++)
		{
			b=(age%6==0&&age%12==0&&age%7==0);
		}
		c=(age=(age/6+age/12+age/7+5+age/2+4));
	printf("丢番图年龄是 %d 岁",age);
//printf要在for循环里,age才能保留其变化 
	}

	return 0;
 } 
