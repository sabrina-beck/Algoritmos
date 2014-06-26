#include <stdio.h>

int main() {
	int i, soma = 0;

	for(i = 1; i <= 100; i++)
		soma += i*i;

	printf("Soma dos quadrados dos 100 primeiros números inteiros = %d\n", soma);

	return 0;
}
