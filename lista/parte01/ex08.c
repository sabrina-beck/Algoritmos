#include <stdio.h>

int main() {
	int inicio, fim, somaImpares, i;

	printf("Digite o inicio e o fim do intervalo: ");
	scanf("%d %d", &inicio, &fim);

	if(inicio % 2 == 0)
		inicio++;
	if(fim % 2 == 0)
		fim--;

	for(i = inicio, somaImpares = 0; i <= fim; i += 2)
		somaImpares += i;

	printf("Soma dos ímpares no intervalo [%d, %d]: %d\n", inicio, fim, somaImpares);

	return 0;
}
