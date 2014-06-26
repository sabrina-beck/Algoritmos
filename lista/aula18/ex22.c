#include <stdio.h>

void imprimir(int i);

int main() {
	imprimir(5);
	return 0;
}

void imprimir(int i) {
	int j;
	if (i > 0) {
		imprimir(i - 1);
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}
