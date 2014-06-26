#include <stdio.h>

int main() {
	int n, i;
	unsigned long int fatorial;

	printf("Digite um valor: ");
	scanf("%d", &n);

	fatorial = 1;
	for(i = 1; i <= n; i++)
		fatorial *= i;

	printf("n! = %lu\n", fatorial);

	return 0;
}
