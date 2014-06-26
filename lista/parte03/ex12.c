#include <stdio.h>

int main() {
	int maior, menor, valor;

	printf("Digite um valor: ");
	scanf("%d", &valor);

	maior = valor;
	menor = valor;

	while(valor > 0) {
		printf("Digite um valor: ");
		scanf("%d", &valor);

		if(valor > maior)
			maior = valor;
		if(valor < menor)
			menor = valor;
	}

	printf("MAIOR: %d\n", maior);
	printf("MENOR: %d\n", menor);

	return 0;
}
