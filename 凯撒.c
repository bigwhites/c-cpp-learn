#include<stdio.h>
#include<stdlib.h>
#define M 26

int main(void)
{
	int i = 0, offset, sum;


	//����ԭ��
	printf("������ԭ�ĵ����ַ���sum��ԭ�Ĳ��س�\n");
	scanf_s("%d", &sum);
	char* str = (char*)malloc(sum * sizeof(char) +1); //��̬���������С
	while ((str[i] = getchar()) != '\n') {
		i++;
	}
	str[i] = '\0';


	//����ƫ����
	printf("������ƫ����offset\n");
	scanf_s("%d", &offset);
	if (offset >= M) {
		offset %= M;
	}


	//����ԭ��
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

	//�������
	printf("ת���ɹ�\n");
	for (i = 0; str[i] != '\0'; ++i) {
		putchar(str[i]);
	}
    return 0;

}