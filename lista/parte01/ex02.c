#include <stdio.h>

int main() {
	int a, b, aux;

	/* Leitura dos dados */
	printf("Digite dois valores a e b: ");
	scanf("%d %d", &a, &b);

	/* Troca os valores das variáveis */
	aux = a;
	a = b;
	b = aux;

	/* Escreve os valores invertidos */
	printf("Os valores digitados -> a: %d e b: %d\n", a, b);

	return 0;
}
