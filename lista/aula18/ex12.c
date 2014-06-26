#include <stdio.h>

#define TAM 10

int maiorElemento (int vet[], int n);

int main() {
	int vet[TAM], i;

	for(i = 0; i < TAM; i++) {
		printf("Digite um valor: ");
		scanf("%d", &vet[i]);
	}

	printf("Maior elemento = %d\n", maiorElemento(vet, TAM));

	return 0;
}

int maiorElemento (int vet[], int n) {
	if(n == 1)
		return vet[0];
	else {
		int x = maiorElemento(vet, n - 1);
		if(vet[n - 1] > x)
			return vet[n -1];
		return x;
	}
	
}
