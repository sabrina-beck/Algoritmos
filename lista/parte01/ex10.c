#include <stdio.h>

int main() {
	int somador, nEsimo, n, i;

	printf("Digite qual é o valor desejado: ");
	scanf("%d", &n);

	somador = 1;
	nEsimo = 2;
	for(i = 0; i < n; i++) {
		nEsimo += somador;
		somador++;
	}

	printf("O valor é: %d\n", nEsimo);

	return 0;
}
