#include<stdio.h> 
int sum(int number0, int n);
int main()
{
	int p = 0, number0 = 0, n = 0;
	printf("请依次数列x（n）的首项和项数以计算和值\n");
	scanf("%d %d", &number0, &n);  //输入首项和项数
	p = sum(number0, n);
	printf("数列x（n）前n项和sum=%d\n", p);
	return 0;
}

int sum(int number0, int n)
{
	int i, j=number0*10, k,c; 
    int sum = 0;
    int x[n] = { number0 }; //定义数列 
  	for(c=1;c<n;c++){
  		x[c]=0;
   } 
  	for (i = 1; i < n; i++) {

		  x[i] = x[i - 1] + j;//赋值数列 
		  j=j*10;
	}
	for (k = 0; k<n; k++) {
		sum = sum + x[k];	//数列求和 
    }
     i=0;
	for(i=0;i<n;i++){
	 	printf("x[%d]=%d ",i+1,x[i]);//输出子项 
	} 
	printf("\n"); 
	return sum;  //返回和值 
}
