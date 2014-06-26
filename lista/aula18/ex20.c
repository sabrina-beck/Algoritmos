#include <stdio.h>
void imprime(int v[], int i, int n);

int main() {
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	imprime(vet, 0, 10);
	printf("\n");
	return 0;
}

void imprime(int v[], int i, int n) {
	if (i < n) {
		printf("%d ", v[i]);
		imprime(v, i + 1, n);
	}
}
