#include<stdio.h>
#include<math.h>
int main()
{
    int n, cnt = 0, first = 1, i;
    int x = 0, t = 0, sum = 0;

    scanf_s("%d", &n);
    first = (int)pow(10, n - 1);
    for (i = first; i < first * 10; i++) {
        sum = 0;
        x = i;
        do {
            t = x % 10;
            x /= 10;
            sum += (int)pow(t, n);
            //printf("%d",sum); 
        } while (x > 0);
        if (sum == i) {
            printf("\n%d ", i);
        }
    }
    return 0;
}
