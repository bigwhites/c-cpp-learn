#include<stdio.h>
int combinatorial(int n, int m);

int main()
{
    int c = 0;
    int n = 0, m = 0;
    printf("������������Ĳ���n��m,�Լ����������ֵ��\n");
   // scanf("%d %d", &n, &m);
   n=6;
   m=4;
    if (n >= m && n >= 1) {
        combinatorial(n, m);
    }
    else {
        printf("�������ֵ����");
    }
    return 0;
}

int combinatorial(int n, int m)
{
    int zi = 1, mu = 1, i, j;
    int p = 0;
    for (i = n; i >=(n-m+1) ; i--) {
        zi = zi * i;
    }
    
	for (j = m; j > 1; j--) {
        mu = mu * j;
    }
    p = zi / mu;
    printf("%d\n", p);
    return 0;
}
