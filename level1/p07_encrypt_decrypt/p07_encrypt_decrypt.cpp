#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
	int cnt,n=0,k=100; 
	char a,c;
	char *s1=(char *)malloc(100);
	char *s2=NULL;
	if (s1 == NULL)   printf("�����ڴ�ʧ��\n");  
	while(1){
		printf("��������1����������0,���롮EOF����ʾ����\n");
		a=_getche();
		if(a=='1'){
			printf("������һ�����ʽ��м���\n");
			while((c=getchar())!=EOF){        //�ж��Ƿ��ļ�������һ������ȡ�ַ�
            	if(k=n){                    //��ǰ�ַ������ȴ��ڵ����ַ����ռ䳤��ʱ
             	   k*=2;                    //��������2��
             	   s2 = (char *)realloc(s1,k);    //���·����ڴ�
            	    if(s2 == NULL){                //�ڴ����ʧ��
             	       free(s1);              //�ͷ��ѷ����ڴ�
            	       printf("�����ڴ�ʧ��\n"); 
            	   }else{                     //�ڴ����ɹ�
             	       s1=s2;
              	  }    
            	}
            	s1[n++]=c;                    //�ַ�����ֵ�ַ�
       		}
        	s1[n]=0; 
			for(cnt=0;s1[cnt]!='\0';cnt++){
				s1[cnt]+=4;
				printf("%c",s1[cnt]);		
			}
		}
		else if(a=='0'){
			printf("������һ�����ʽ��н���\n");
			while((c=getchar())!=EOF){        //�ж��Ƿ��ļ�������һ������ȡ�ַ�
           	if(k=n){                    //��ǰ�ַ������ȴ��ڵ����ַ����ռ䳤��ʱ
			    k*=2;                    //��������2��
           	    s2 = (char *)realloc(s1,k);    //���·����ڴ�
           	    if(s2 == NULL){                //�ڴ����ʧ��
           	        free(s1);              //�ͷ��ѷ����ڴ�
           	        printf("�����ڴ�ʧ��\n"); 
            	    }else{                     //�ڴ����ɹ�
           	        s1=s2;
            	  }    
            	}
            	s1[n++]=c;                    //�ַ�����ֵ�ַ�
       		}
        	s1[n]=0; 
			for(cnt=0;s1[cnt]!='\0';cnt++){
				s1[cnt]-=4;
				printf("%c",s1[cnt]);		
			}
		}
		else{
			printf("�������\n");
			continue;
		} 

	}
	

return 0;
}

  
