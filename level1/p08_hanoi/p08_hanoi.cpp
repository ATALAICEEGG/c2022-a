#include<stdio.h>
#include<stdlib.h>

void move(char a,char b){
	printf("%c -> %c\n",a,b);
}

void hanoi(int i,int a,int b,int c){
	if(i>=1){
		if(i==1){
		move(a,c);
	}	
		else{
			hanoi(i-1,a,c,b);
			move(a,c);
			hanoi(i-1,b,a,c);
		}

	}

}	
	


int main(){
	hanoi(64,'A','B','C');
	return 0;
}
