#include <stdio.h>

enum bool {
	false, true
};

typedef enum bool bool;

int abs(int a) {
	if(a < 0)
		return -a;
	return a;
}

void imprime(int vet[], int n) {
	int i;
	printf("(");
	for(i = 0; i < n - 1; i++)
		printf("%d ", vet[i] + 1);
	printf("%d)", vet[i] + 1);
}

bool valida(int k, int rainhas[]) {
	int i;

	for(i = 0; i < k - 1; i++)
		if(rainhas[i] == rainhas[k] /*não pode estar na mesma coluna*/
			|| abs(rainhas[i] - rainhas[k]) == (k - i) 
			/*não pode estar na mesma diagonal*/)
			return 0;
	return 1;
}

void nRainhas(int k, int rainhas[], int n) {
	if(k == n)
		imprime(rainhas, k);
	else {
		int i;
		for(i = 0; i < n; i++) {
			rainhas[k] = i;
			if(valida(k, rainhas))
				nRainhas(k + 1, rainhas, n);
		}
	}
}

int main() {
	int rainhas[8];

	printf("Problema das 8 rainhas:\n");
	nRainhas(0, rainhas, 8);

	return 0;
}
