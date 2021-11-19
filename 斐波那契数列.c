#include<stdio.h>
long long sum(int* a, int n);

int main(void)
{
	int n;
	long long result = 0;
	printf("ÊäÈëÏîÊın=");
	scanf("%d", &n);
	int* a = (int*)calloc(n + 2, sizeof(int));
	a[1] = a[2] = 1;
	for (int i = 3; i <= n; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}
	for (int j = 1; j <= n; j++) {
		printf("a[%d]=%d \t  ", j, a[j]);
    }
	result = sum(a, n);
	printf("\nsum=%d", result);

	return 0;
}

long long sum(int* a, int n) {
	long long p = 0;
	for (int i = 1; i <= n; i++) {
		p += a[i];

	}
	return p;
}