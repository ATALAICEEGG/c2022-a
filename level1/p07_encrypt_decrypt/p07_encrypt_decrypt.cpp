#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
	int cnt,n=0,k=100; 
	char a,c;
	char *s1=(char *)malloc(100);
	char *s2=NULL;
	if (s1 == NULL)   printf("分配内存失败\n");  
	while(1){
		printf("加密输入1，解密输入0,输入‘EOF’表示结束\n");
		a=_getche();
		if(a=='1'){
			printf("请输入一个单词进行加密\n");
			while((c=getchar())!=EOF){        //判断是否到文件结束，一个个读取字符
            	if(k=n){                    //当前字符串长度大于等于字符串空间长度时
             	   k*=2;                    //长度增长2倍
             	   s2 = (char *)realloc(s1,k);    //重新分配内存
            	    if(s2 == NULL){                //内存分配失败
             	       free(s1);              //释放已分配内存
            	       printf("分配内存失败\n"); 
            	   }else{                     //内存分配成功
             	       s1=s2;
              	  }    
            	}
            	s1[n++]=c;                    //字符串赋值字符
       		}
        	s1[n]=0; 
			for(cnt=0;s1[cnt]!='\0';cnt++){
				s1[cnt]+=4;
				printf("%c",s1[cnt]);		
			}
		}
		else if(a=='0'){
			printf("请输入一个单词进行解密\n");
			while((c=getchar())!=EOF){        //判断是否到文件结束，一个个读取字符
           	if(k=n){                    //当前字符串长度大于等于字符串空间长度时
			    k*=2;                    //长度增长2倍
           	    s2 = (char *)realloc(s1,k);    //重新分配内存
           	    if(s2 == NULL){                //内存分配失败
           	        free(s1);              //释放已分配内存
           	        printf("分配内存失败\n"); 
            	    }else{                     //内存分配成功
           	        s1=s2;
            	  }    
            	}
            	s1[n++]=c;                    //字符串赋值字符
       		}
        	s1[n]=0; 
			for(cnt=0;s1[cnt]!='\0';cnt++){
				s1[cnt]-=4;
				printf("%c",s1[cnt]);		
			}
		}
		else{
			printf("输入错误\n");
			continue;
		} 

	}
	

return 0;
}

  
