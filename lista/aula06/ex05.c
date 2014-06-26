#include <stdio.h>

int main() {
	int i, j, n, soma;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(j = 1; j <= n; j++) {
		soma = 0;
		for(i = 1; i <= j; i++)
			soma += i;
		printf("Soma %d: %d\n", j, soma);
	}


	return 0;
}
