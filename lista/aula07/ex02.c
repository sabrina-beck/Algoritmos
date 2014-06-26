#include <stdio.h>

int main() {
	int n, soma, lido, i;

	printf("Digite a quantidade de valores a serem lidos: ");
	scanf("%d", &n);

	soma = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &lido);
		soma += lido;
	}

	printf("Soma: %d\n", soma);

	return 0;
}
