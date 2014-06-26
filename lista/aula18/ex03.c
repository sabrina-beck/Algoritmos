#include <stdio.h>

#define TAM 10

int somaElementos(int vet[], int n);

int main() {
	int vet[TAM], i, soma;

	for(i = 0; i < TAM; i++) {
		printf("Digite um valor: ");
		scanf("%d", &vet[i]);
	}

	soma = somaElementos(vet, TAM);

	printf("Soma: %d\n", soma);

	return 0;
}

int somaElementos(int vet[], int n) {
	if(n <= 0)
		return 0;
	return vet[n-1] + somaElementos(vet, n-1);
}
