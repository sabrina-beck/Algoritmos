#include <stdio.h>

int main() {
	int valor;

	printf("Digite um valor: ");
	scanf("%d", &valor);

	if((valor % 3 == 0 && valor % 5 != 0) ||
		(valor % 3 != 0 && valor % 5 == 0))
		printf("É divisivel por 3 ou 5.\n");
	else
		printf("Não é divisível por 3 ou 5.\n");

	return 0;
}
