#include <stdio.h>

int main() {
	int maior, lido, n, i;

	printf("Digite a quantidade de valores a serem lidos: ");
	scanf("%d", &n);

	scanf("%d", &maior);
	for(i = 1; i < n; i++) {
		scanf("%d", &lido);
		if(lido > maior)
			maior = lido;
	}

	printf("Maior: %d\n", maior);

	return 0;
}
