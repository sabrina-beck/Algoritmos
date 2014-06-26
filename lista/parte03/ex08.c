#include <stdio.h>

int main() {
	int n, i, j;

	printf("Dimensão: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			if(i == j)
				printf("x");
			else
				printf("+");
		printf("\n");
	}

	return 0;
}
