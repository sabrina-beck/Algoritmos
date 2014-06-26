#include <stdio.h>

int main() {
	int x;
	unsigned int n, i, pot = 1;

	printf("Digite um numero inteiro qualquer: ");
	scanf("%d", &x);

	printf("Digite um numero inteiro positivo: ");
	scanf("%u", &n);

	for(i = 0; i < n; i++)
		pot *= x;

	printf("%d^%u = %u\n", x, n, pot);

	return 0;
}
