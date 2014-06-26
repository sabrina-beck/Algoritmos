#include <stdio.h>

int main() {
	double vet1[5], vet2[5];
	int i, j;

	for(i = 0; i < 5; i++) {
		printf("Digite um valor: ");
		scanf("%lf", &vet1[i]);
	}

	for(i = 0; i < 5; i++) {
		printf("Digite um valor: ");
		scanf("%lf", &vet2[i]);
	}

	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			if(vet1[i] == vet2[j]) {
				printf("vet1[%d] == vet2[%d] == %.2f\n", i, j, vet1[i]);
			}

	return 0;
}
