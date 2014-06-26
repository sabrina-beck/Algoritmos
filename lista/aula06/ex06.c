#include <stdio.h>

int main() {
	int i, j, soma, n;

	printf("digite um valor: ");
	scanf("%d", &n);

	soma = 0;
	for(j = 1; j <= n; j++)
		for(i = 1; i <= j; i++)
			soma++;
	printf("Soma: %d\n", soma);

	return 0;
}
