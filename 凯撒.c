#include<stdio.h>
#include<stdlib.h>
#define M 26

int main(void)
{
	int i = 0, offset, sum;


	//读入原文
	printf("请输入原文的总字符数sum和原文并回车\n");
	scanf_s("%d", &sum);
	char* str = (char*)malloc(sum * sizeof(char) +1); //动态分配数组大小
	while ((str[i] = getchar()) != '\n') {
		i++;
	}
	str[i] = '\0';


	//设置偏移量
	printf("请输入偏移量offset\n");
	scanf_s("%d", &offset);
	if (offset >= M) {
		offset %= M;
	}


	//加密原文
	for(i = 0; str[i] != 0; i++){
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] - 'A' + offset < M) {
				str[i] = str[i] + offset;
			}
			else {
				str[i] = str[i] - (M - offset);
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if ((str[i] - 'a' + offset) < M) {
				str[i] = str[i] + offset;
			}
			else {
				str[i] = str[i] - (M - offset);
			}
		}
    }

	//输出密文
	printf("转换成功\n");
	for (i = 0; str[i] != '\0'; ++i) {
		putchar(str[i]);
	}
    return 0;

}