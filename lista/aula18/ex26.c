#include <stdio.h>

#define TAM 8

int menorElemento(int vet[], int n);
int maiorElemento(int vet[], int n);

int main() {
	int vet[] = {1, 99, 200, 945, 9289, 19, 2, 1};

	printf("MAIOR: %d\n", maiorElemento(vet, TAM));
	printf("MENOR: %d\n", menorElemento(vet, TAM));

	return 0;
}

int menorElemento(int vet[], int n) {
	if(n == 1)
		return vet[0];
	else {
		int menorDoResto = menorElemento(vet, n -1);
		if(vet[n - 1] < menorDoResto)
			return vet[n - 1];
		return menorDoResto;
	}
}

int maiorElemento(int vet[], int n) {
	if(n == 0)
		return 0;
	else {
		int maiorDoResto = maiorElemento(vet, n - 1);
		if(vet[n - 1] > maiorDoResto)
			return vet[n - 1];
		return maiorDoResto;
	}
}
