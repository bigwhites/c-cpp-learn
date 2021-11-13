#include<stdio.h>
int combinatorial(int n, int m);

int main()
{
    int c = 0;
    int n = 0, m = 0;
    printf("请输入组合数的参数n、m,以计算组合数的值。\n");
   // scanf("%d %d", &n, &m);
   n=6;
   m=4;
    if (n >= m && n >= 1) {
        combinatorial(n, m);
    }
    else {
        printf("你输入的值有误。");
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
