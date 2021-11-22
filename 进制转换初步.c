#include<stdio.h>
#include<Windows.h>

int main(void)
{
start:
	
	int x, type, typeto, i = 0;
	int t[1000] = { 0 };
	printf("请输入原数字的进制（支持8 10 16进制):");
    scanf_s("%d", &type);
    printf("\n请输入形如的原数字:");
   switch (type) {
	case 10:
		scanf_s("%d", &x); break;
	case 8:
		scanf_s("%o", &x); break;
	case 16:
		scanf_s("%x", &x); break;
	default:
		printf("error\n");
		goto start;

	}
   int x0;
   x0 = x;


back:
   printf("\n请输入要转换成的进制(支持2-10和16进制）：");
   scanf_s("%d", &typeto);
   if (typeto == 16) printf("\n(x)16=%#x",x);
   else if (typeto == 8) printf("\n(x)=%#o", x);
   else if ((typeto > 10 || typeto < 2))  goto back;
   else {
	   while (x != 0) {
		   t[i] = x % typeto;
		   x /= typeto;
		   i++;
	   }
	   //printf("\ni=%d\n", i);
	   printf("\n(x)%d=(",type);
	   for (int j = i-1; j >=0; j--) {
		   printf("%d", t[j]);
	   }
	   if (i == 0) printf("0");
	   printf(")%d", typeto);

   }
   
	
   system("pause");
   return 0;
}