#include <stdio.h>
#include <string.h>
struct BOOK {
	char name[35];
	double price;
};
void searchbook(struct BOOK* p, int n);

int main(void) {
	int n, i;
	struct BOOK a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("\n");          /*非常重要*/
		gets(a[i].name);
		scanf("%lf", &a[i].price);
	}

	struct BOOK* p = &a[0];
	searchbook(p, n);
	return 0;
}

void searchbook( struct BOOK* p, int n) {
	int i, min, max, index_min, index_max;
	min = max = p[0].price;
	index_max = index_min = 0;
	for (i = 0; i < n; i++) {
		if (p[i].price > max) {
			max = p[i].price;
			index_max = i;
		}
		if (p[i].price < min) {
			min = p[i].price;
			index_min = i;
		}
	}


	printf("%.2f, %s\n", p[index_max].price, p[index_max].name);
	printf("%.2f, %s\n", p[index_min].price, p[index_min].name);
}
