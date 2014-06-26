#include <stdio.h>

int buscaBinaria(int vet[], int n, int x);

int main() {
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("%d está em %d\n", 4, buscaBinaria(vet, 10, 4));
	printf("%d está em %d\n", 10, buscaBinaria(vet, 10, 10));
	printf("%d está em %d\n", 20, buscaBinaria(vet, 10, 20));

	return 0;
}

int busca(int vet[], int inicio, int fim, int x) {
	int meio;
	if(inicio > fim)
		return -1;
	meio = (inicio + fim) / 2;
	if(vet[meio] == x)
		return meio;
	if(vet[meio] < x)
		return busca(vet, meio + 1, fim, x);
	return busca(vet, inicio, meio - 1, x);
}

int buscaBinaria(int vet[], int n, int x) {
	return busca(vet, 0, n - 1, x);
}
