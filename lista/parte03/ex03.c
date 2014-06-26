#include <stdio.h>
#include <math.h>

int main() {
	int n, i;
	int soma = 0, somaQuadrados = 0;

	printf("Quantos valores serão digitados? ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		int valor;
		scanf("%d", &valor);

		soma += valor;
		somaQuadrados += pow(valor, 2);
	}

	printf("Soma dos quadrados = %d\n", somaQuadrados);
	printf("Quadrado da soma = %.0f\n", pow(soma, 2));

	return 0;
}
