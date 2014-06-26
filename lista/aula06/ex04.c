#include <stdio.h>

int main() {
	int n, soma, i;

	printf("Digite um valor: ");
	scanf("%d", &n);

	soma = 0;
	for(i = 1; i <= n; i++)
		soma += i;

	printf("Somatorio: %d\n", soma);

	return 0;
}
