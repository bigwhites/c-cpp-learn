#include<stdio.h>

int main()
{
	int x;
	int isprime;
	for (x = 1; x <= 1000; x++) {
		int i;
	   isprime = 1;
		
		for (i = 2; i < x; i++) {
			if (x % i == 0) {   //被整除了，不是素数
				isprime = 0;
			
			}
			if (isprime == 1) {       //没被整除，是素数
				printf("%d\n", x);
				break;
				
			}
		 }
		
	}
	return 0;
}
