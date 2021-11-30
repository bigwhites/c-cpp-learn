#include<stdio.h>
#include<Windows.h>
int main(void)
{
	    long long num;
		int A=0, B=0, C;
		printf("\n请输入前12位代码:\n");
		scanf_s("%12lld", &num);
		long long  t = num;
		int J[13] = { 0 };
		int O[13] = { 0 };
		for (int i = 1; i <= 12; ++i)
		{
			int e;
			e = (int)(num%10);
			num /= 10;
			if (i % 2 != 0)
			{
				J[i] = e;
			}
			else
			{
				O[i] = e;
			}
		}
		for (int j = 1; j <= 12; ++j)
		{
			A += J[j];
			B += O[j];
		}
		A *=3;
		int d;
		d = A + B;
		C = d%10;
		int result = 0;
		result = 10 - C;
		if (result == 10)  result = 0;
		printf("\n13位代码为： %lld%d", t, result);
system("pause");
return 0;
}
/*    EAN-13 末位校验码计算
	  计算校验位的步骤如下：
1.       将最右边一个数位作为“奇数”位，从右向左为每个字符指定奇数/偶数位。
2.       对所有奇数位上的数值求和，将结构乘以3。
3.       对所有偶数位上的数值求和。
4.       对第2步和第3步计算的结果求和。
5.       校验位的数字加上用第4步计算的总和数应该能够被10整除。
6.       如果第4步计算的总和数能够被10整除，校验位就是“0”（不是10）
*/
