#include<stdio.h>

int main()
{
	int x;
	int isprime;
	for (x = 1; x <= 1000; x++) {
		int i;
	   isprime = 1;
		
		for (i = 2; i < x; i++) {
			if (x % i == 0) {   //�������ˣ���������
				isprime = 0;
			
			}
			if (isprime == 1) {       //û��������������
				printf("%d\n", x);
				break;
				
			}
		 }
		
	}
	return 0;
}