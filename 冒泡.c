#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void bubble(int x[], int total0);
int main(void)
{
	int total,cnt1,t,cnt2;
	
	// 读入数列 
	printf("输入数列总项数");
	scanf("%d", &total);
	printf("\n输入数列的各项以排序\n");
	int *x=(int*)malloc(sizeof(int)*(total+2));
	while (cnt1 !=total) {
		scanf("%d", &x[cnt1]);
		cnt1++;
	
	}

    //输出原数列 
	printf("before bubble:\n");
    for( t=0;t<total;t++){
			 printf("x[%d]=%d  ",t,x[t]);
		}
		printf("\n");
	
	//调用冒泡排序函数 
	bubble(x, total);

    //输出排列好的数列 
    printf("bubble done:\n"); 
	for (cnt2 = 0; cnt2<total;cnt2++) {
		printf("x`[%d]=%d  ", cnt2, x[cnt2]);
	}
	
	system("pause"); 
	return 0;
}


void bubble(int x[], int total) {
int i, j,c=0;

	for (i = 0; i < total; i++) {
		for (j = 0; j < total - i;j++) {
			if (x[j] > x[j + 1]) {
				c = x[j];
				x[j] = x[j+1];
				x[j+1] = c;
			}
		}
		
	}

}
