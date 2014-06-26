#include <stdio.h>

int main() {
	int n, i, j, cont;

	printf("Quantas linhas? ");
	scanf("%d", &n);

	for(i = 1, cont = 1; i <= n; i++) {
		for(j = 0; j < i; j++, cont++)
			printf("%d ", cont);
		printf("\n");
	}

	return 0;
}
