#include<stdio.h>
#include<Windows.h>

int main(void)
{
start:
	
	int x, type, typeto, i = 0;
	int t[1000] = { 0 };
	printf("������ԭ���ֵĽ��ƣ�֧��8 10 16����):");
    scanf_s("%d", &type);
    printf("\n�����������ԭ����:");
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
   printf("\n������Ҫת���ɵĽ���(֧��2-10��16���ƣ���");
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