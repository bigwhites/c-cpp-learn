//����������ٸ� 
#include<stdio.h>
#include<windows.h>


void search(int a,int b,int c,int t);
int  main(void){
road:	
printf("ax+by+cz=t\n");
printf("���� a b c��t(ȫ����0)��������x y��z \n");
int a,b,c,t;
//a=2;
//b=8;
//c=4;
//t=1940; 
scanf("%d %d %d %d",&a,&b,&c,&t);
int stop=0;
search(a,b,c,t);
  while(!stop){


printf("���Ҫ���������밴0��ֹͣ��1\n");
scanf("%d",&stop); 
  if(!stop){
     goto road;
    }

  }
  system("pause");
  return 0;
}
void search(int a,int b,int c,int t){
 int cnt=0,x,y,z;
 int xm=(t/a)+1,ym=(t/b)+1,zm=(t/c)+1;  //���Ƹ����Χ����ѭ������ �������У� 
 long long cnt0=0;
 for(x=0;x<=xm;x++){
	for(y=0;y<=ym;y++){
		for(z=0;z<=zm;z++,cnt0++){
			if(a*x+b*y+c*z==t){
				cnt++;
				printf("%d*%d+%d*%d+%d*%d=%d  �ǵ�%d����    and x=%d y=%d z=%d\n  ",a,x,b,y,c,z,t,cnt,x,y,z);
			}
		}
	}
 }
	
	 printf("����%d��  ��ѭ���ܴ���=%ld\n",cnt,cnt0) ;
	
}
