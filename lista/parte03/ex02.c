#include <stdio.h>

int main() {
	int n, i;
	unsigned long int fatorial = 1;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		fatorial *= i;

	printf("%d! = %lu\n", n, fatorial);

	return 0;
}
