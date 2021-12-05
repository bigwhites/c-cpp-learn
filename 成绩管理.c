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
		double total; //�ܷ� 
	}stu;
void scan_stu(stu *class,int n);
void sort_stu(stu*class,int n);
void statistics(stu*class,int n);


int main(void)
{
//��ʼ�� 
	int n;
	printf("����ѧ������\n");
    scanf_s("%d", &n);
	stu* class = (stu*)malloc((n + 1) * sizeof(class));
	scan_stu(class,n); //����ѧ����Ϣ 
    printf("\n����ѧ�����ݶ������\n");
    
//���ֶܷ�ѧ������ 
	sort_stu(class,n);
	
//�������������	
	int o; 
	for(o=1;o<=n;++o)
	{
		printf("\n �ܷ�������%dλΪ%s ���ܷ�Ϊ%f\n",o,class[o].name,class[o].total);
		printf("����%.1f\t��ѧ%.1f\tӢ��%.1f\t����%.1f\t\n",class[o].yu,class[o].math,class[o].en,class[o].ph);
		printf("��ѧ%.1f\t����%.1f\n",class[o].chem0,class[o].bio0);
	}
    statistics(class,n);
	 
system("pause");
return 0;
}


void scan_stu(stu* class,int n)  //�������뺯�� 
{
	int i;
	for(i=1;i<=n;++i)
	{
		printf("\n�����%d��ѧ�����������Ʒ���\n",i);
		scanf_s("%10s",class[i].name);
		fflush(stdin);
		scanf_s("%lf %lf %lf %lf %lf %lf",&class[i].yu,&class[i].math,&class[i].en,&class[i].ph,&class[i].chem0,&class[i].bio0);
		class[i].total=class[i].yu+class[i].math+class[i].en+class[i].ph+class[i].bio0+class[i].chem0;		
	}
}

void statistics(stu*class,int n) //ͳ�ƺ��� 
{
	double yu_=0,math_=0,en_=0,ph_=0,chem0_=0,bio0_=0;
	int k,q;
	int nyu=0,nmath=0,nen=0,nph=0; //���Ʋ��������� 
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
	printf("\n���ƾ���Ϊ ����%.2f  ��ѧ%.2f  Ӣ��%.2f  ����%.2f  ��ѧ%.2f   ����%.2f\n",yu_,math_,en_,ph_,chem0_,bio0_);
	for(q=1;q<=n;++q)
	{
		if(class[q].yu<90.0)	nyu++;
		if(class[q].math<90.0)	nmath++; 
		if(class[q].en<90.0)    nen++; 
		if(class[q].ph<60.0)    nph++;
	}
	printf("\n����������Ϊ:  ����%d  ��ѧ%d    Ӣ��%d   ����%d\n",nyu,nmath,nen,nph);
}

void sort_stu(stu*class,int n)  //stu�ṹ��ð�������� 
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
