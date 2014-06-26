#include <stdio.h>

int main() {
	double vet1[5], vet2[5], produtoInterno = 0.0;
	int i;

	for(i = 0; i < 5; i++) {
		printf("Digite um valor: ");
		scanf("%lf", &vet1[i]);
	}

	for(i = 0; i < 5; i++) {
		printf("Digite um valor: ");
		scanf("%lf", &vet2[i]);
	}

	for(i = 0; i < 5; i++)
		produtoInterno += vet1[i] * vet2[i];

	printf("Produto interno = %.2f\n", produtoInterno);

	return 0;
}
