#include<stdio.h>
#include<stdlib.h>

int partition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
void printarray(int* a, int len);
int len_1;
int main(void)
{
	int len;
	printf("�������ݸ�����");
	scanf("%d", &len);
	len_1 = len;
	printf("\n");
	int* a = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; ++i) scanf("%d", a + i);
	printarray(a, len);
	quickSort(a, 0, len - 1);
	puts("\n\n<<<�������>>>");
	printarray(a, len);
	fflush(stdin);
	getchar();
	return 0;
}

int partition(int* a, int low, int high)
{
	int pivot = a[low];//ȡ�����һ��Ԫ��Ϊ��׼ֵ
	while (low < high)
	{
		while (low < high && a[high] >= pivot) --high; //���ұߵ������ڻ�׼��һֱ���� ֱ���ҵ�С�ڻ�׼ֵ��
		a[low] = a[high];//��high��ֵ��low ���ҵ���С�ڻ�׼�����Ƶ���� ��������λ
		while (low < high && a[low] <= pivot) ++low;//����ߵ���С�ڻ�׼��ʱ���һֱ����ֱ���ҵ����ڻ�׼ֵ��
		a[high] = a[low];
	}
	a[low] = pivot;//high low �غ�ʱ�ѻ�׼ֵ�ŵ���ȷλ����
	return low;//��׼ֵ������λ��
}

void quickSort(int* a, int low, int high)
{
	if (low < high)//�ݹ����������
	{
		int pivotpos = partition(a, low, high);
		printarray(a, len_1);
		printf("\n");
		quickSort(a, low, pivotpos - 1);//�ݹ黮����ߵ�������
		quickSort(a, pivotpos + 1, high);
	}
}
void printarray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
}