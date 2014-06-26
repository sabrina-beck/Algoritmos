#include <stdio.h>

int main() {
	int a, b, c;
	float media;

	/* Leitura dos dados */
	printf("Digite 3 valores: ");
	scanf("%d %d %d", &a, &b, &c);

	/* Processamento */
	media = (a + b + c) / 3.0;

	/* Exibicao dos dados */
	printf("Média: %.2f\n", media);

	return 0;
}
