#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct student
	{
		char name[10];
		double yu;
		double math;
		double en;
		double ph;
		double chem0; 
		double bio0;
		double total; //总分 
	}stu;
void scan_stu(stu *class,int n);
void sort_stu(stu*class,int n);
void statistics(stu*class,int n);


int main(void)
{
//初始化 
	int n;
	printf("输入学生总数\n");
    scanf_s("%d", &n);
	stu* class = (stu*)malloc((n + 1) * sizeof(class));
	scan_stu(class,n); //读入学生信息 
    printf("\n所有学生数据读入完成\n");
    
//按总分对学生排序 
	sort_stu(class,n);
	
//输出排名分数表	
	int o; 
	for(o=1;o<=n;++o)
	{
		printf("\n 总分排名第%d位为%s ，总分为%f\n",o,class[o].name,class[o].total);
		printf("语文%.1f\t数学%.1f\t英语%.1f\t物理%.1f\t\n",class[o].yu,class[o].math,class[o].en,class[o].ph);
		printf("化学%.1f\t生物%.1f\n",class[o].chem0,class[o].bio0);
	}
    statistics(class,n);
	 
system("pause");
return 0;
}


void scan_stu(stu* class,int n)  //数据输入函数 
{
	int i;
	for(i=1;i<=n;++i)
	{
		printf("\n输入第%d个学生的姓名各科分数\n",i);
		scanf_s("%10s",class[i].name);
		fflush(stdin);
		scanf_s("%lf %lf %lf %lf %lf %lf",&class[i].yu,&class[i].math,&class[i].en,&class[i].ph,&class[i].chem0,&class[i].bio0);
		class[i].total=class[i].yu+class[i].math+class[i].en+class[i].ph+class[i].bio0+class[i].chem0;		
	}
}

void statistics(stu*class,int n) //统计函数 
{
	double yu_=0,math_=0,en_=0,ph_=0,chem0_=0,bio0_=0;
	int k,q;
	int nyu=0,nmath=0,nen=0,nph=0; //各科不及格人数 
	for(k=1;k<=n;k++)
	{
		yu_+=class[k].yu;
		math_+=class[k].math;
		en_+=class[k].en;
		ph_+=class[k].ph;
		chem0_+=class[k].chem0;
		bio0_+=class[k].bio0;
    }
    yu_/=n;
    math_/=n;
	en_/=n;
	ph_/=n;
	chem0_/=n;
	bio0_/=n;
	printf("\n各科均分为 语文%.2f  数学%.2f  英语%.2f  物理%.2f  化学%.2f   生物%.2f\n",yu_,math_,en_,ph_,chem0_,bio0_);
	for(q=1;q<=n;++q)
	{
		if(class[q].yu<90.0)	nyu++;
		if(class[q].math<90.0)	nmath++; 
		if(class[q].en<90.0)    nen++; 
		if(class[q].ph<60.0)    nph++;
	}
	printf("\n不及格人数为:  语文%d  数学%d    英语%d   物理%d\n",nyu,nmath,nen,nph);
}

void sort_stu(stu*class,int n)  //stu结构体冒泡排序函数 
{
	int i,j;
	for(i=1;i<=n;++i)
    {
    	for(j=1;j<=n-i;j++)
    	{
		 	stu t;
    		if(class[j+1].total>class[j].total)
    		{
    		    t=class[j];
    		    class[j]=class[j+1];
    	        class[j+1]=t;    
			}
		}
	}
}
