#include <stdio.h>

int main() {
	char nome1[100], nome2[100];
	FILE* arq1, arq2;
	int numero;

	printf("Qual é o arquivo de entrada? ");
	scanf("%s", nome1);

	arq1 = fopen(nome1, "r");

	if(arq1 == NULL) [
		printf("Erro ao abrir o arquivo %s para leitura.\n", nome1);
		return 0;
	}

	printf("Qual é o arquivo de saida? ");
	scanf("%s", nome2);

	arq2 = fopen(nome2, "w");

	if(arq2 != NULL) {
		printf("Erro ao abrir o arquivo %s para escrita.\n");
		return 0;
	}

	/*TODO*/

	return 0;
}
