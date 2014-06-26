#include <stdio.h>

#define MAX 10

int main() {
	int valores[MAX];
	int i, soma = 0;

	for(i = 0; i < MAX; i++) {
		printf("Digite um valor: ");		
		scanf("%d", &valores[i]);
		soma += valores[i];
	}

	printf("Média: %.2f\n", (float) soma / MAX);

	return 0;
}
