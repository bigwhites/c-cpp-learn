#include<stdio.h> 
int sum(int number0, int n);
int main()
{
	int p = 0, number0 = 0, n = 0;
	printf("����������x��n��������������Լ����ֵ\n");
	scanf("%d %d", &number0, &n);  //�������������
	p = sum(number0, n);
	printf("����x��n��ǰn���sum=%d\n", p);
	return 0;
}

int sum(int number0, int n)
{
	int i, j=number0*10, k,c; 
    int sum = 0;
    int x[n] = { number0 }; //�������� 
  	for(c=1;c<n;c++){
  		x[c]=0;
   } 
  	for (i = 1; i < n; i++) {

		  x[i] = x[i - 1] + j;//��ֵ���� 
		  j=j*10;
	}
	for (k = 0; k<n; k++) {
		sum = sum + x[k];	//������� 
    }
     i=0;
	for(i=0;i<n;i++){
	 	printf("x[%d]=%d ",i+1,x[i]);//������� 
	} 
	printf("\n"); 
	return sum;  //���غ�ֵ 
}
