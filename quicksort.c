#include<stdio.h>
#include<stdlib.h>

int partition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
void printarray(int* a, int len);
int len_1;
int main(void)
{
	int len;
	printf("输入数据个数：");
	scanf("%d", &len);
	len_1 = len;
	printf("\n");
	int* a = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; ++i) scanf("%d", a + i);
	printarray(a, len);
	quickSort(a, 0, len - 1);
	puts("\n\n<<<排序完成>>>");
	printarray(a, len);
	fflush(stdin);
	getchar();
	return 0;
}

int partition(int* a, int low, int high)
{
	int pivot = a[low];//取数组第一个元素为基准值
	while (low < high)
	{
		while (low < high && a[high] >= pivot) --high; //当右边的数大于基准就一直左移 直到找到小于基准值的
		a[low] = a[high];//把high的值给low 把找到的小于基准的数移到左边 并产生空位
		while (low < high && a[low] <= pivot) ++low;//当左边的数小于基准的时候就一直右移直到找到大于基准值的
		a[high] = a[low];
	}
	a[low] = pivot;//high low 重合时把基准值放到正确位置上
	return low;//基准值的最终位置
}

void quickSort(int* a, int low, int high)
{
	if (low < high)//递归继续的条件
	{
		int pivotpos = partition(a, low, high);
		printarray(a, len_1);
		printf("\n");
		quickSort(a, low, pivotpos - 1);//递归划分左边的子数组
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