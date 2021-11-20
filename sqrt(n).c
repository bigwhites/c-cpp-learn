/*这是一个求sqrtn和的程序*/

#include<stdio.h>
#include<math.h>

int main(void)
{
	int N;
	double sum = 0;
	printf("enter N ="); 
	scanf_s("%d", &N);
	for (int i = N; i >= 1; --i) {
		sum += sqrt(i);
	}
	printf("\nsum = %.2f", sum);

	return 0;
}
