#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int i=0,j,judge=0,x;

int main(){
	printf("请输入一串长度不超过10的字符\n");
	char str[15];                                                                                                                                                                                                                                                   
	scanf("%s",&str);
	
	while(1){
		HANDLE handle;                             
    	CONSOLE_SCREEN_BUFFER_INFO screen;  
		GetConsoleScreenBufferInfo(handle, &screen); 
		x=100;
		//x=screen.srWindow.Right-screen.srWindow.Left;不知道为什么读取控制台的右边和左边都是0 
		system("cls");
		if(judge==0){
			for(j=0;j<i&&j<x;j++){
				printf(" ");
			}
			puts(str);
			i++; 
			Sleep(25);
		}
		else if(judge==1){
			for(int j=x;j>(x-i)&&i>0;j--){
				printf(" ");
			}
			puts(str);
			i--; 
			Sleep(25);
		}
		if(i==x&&judge==0){
			judge=(judge+1)%2;
		}
		else if(i==0&&judge==1){
			judge=(judge+1)%2;
		}
		CloseHandle(handle); 
	}
		
	
		
	
 
}
