//不定方程穷举根 
#include<stdio.h>
#include<windows.h>


void search(int a,int b,int c,int t);
int  main(void){
road:	
printf("ax+by+cz=t\n");
printf("输入 a b c和t(全大于0)计算所有x y和z \n");
int a,b,c,t;
//a=2;
//b=8;
//c=4;
//t=1940; 
scanf("%d %d %d %d",&a,&b,&c,&t);
int stop=0;
search(a,b,c,t);
  while(!stop){


printf("如果要继续计算请按0，停止按1\n");
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
 int xm=(t/a)+1,ym=(t/b)+1,zm=(t/c)+1;  //限制根最大范围减少循环次数 （不可行） 
 long long cnt0=0;
 for(x=0;x<=xm;x++){
	for(y=0;y<=ym;y++){
		for(z=0;z<=zm;z++,cnt0++){
			if(a*x+b*y+c*z==t){
				cnt++;
				printf("%d*%d+%d*%d+%d*%d=%d  是第%d个解    and x=%d y=%d z=%d\n  ",a,x,b,y,c,z,t,cnt,x,y,z);
			}
		}
	}
 }
	
	 printf("共有%d解  且循坏总次数=%ld\n",cnt,cnt0) ;
	
}
