#include <stdio.h>

int main() {
	FILE *arq1, *arq2, *arqOut;
	char nomeArq1[100], nomeArq2[100], nomeArqOut[100];
	int numero1, numero2, f1, f2;

	printf("Qual o nome do primeiro arquivo? ");
	scanf("%s", nomeArq1);
	arq1 = fopen(nomeArq1, "r");

	if(arq1 == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nomeArq1);
		return 0;
	}

	printf("Qual o nome do segundo arquivo? ");
	scanf("%s", nomeArq2);
	arq2 = fopen(nomeArq2, "r");

	if(arq2 == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nomeArq2);
		fclose(arq1);
		return 0;
	}

	printf("Qual o nome do arquivo de saída? ");
	scanf("%s", nomeArqOut);
	arqOut = fopen(nomeArqOut, "w");

	if(arqOut == NULL) {
		printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArqOut);
		fclose(arq1);
		fclose(arq2);
		return 0;
	}

	f1 = fscanf(arq1, "%d", &numero1);
	f2 = fscanf(arq2, "%d", &numero2);

	while(f1 != EOF && f2 != EOF) {
		if(numero1 < numero2) {
			fprintf(arqOut, "%d\n", numero1);
			f1 = fscanf(arq1, "%d", &numero1);
		} else {
			fprintf(arqOut, "%d\n", numero2);
			f2 = fscanf(arq2, "%d", &numero2);
		}
	}

	while(f1 != EOF) {
		fprintf(arqOut, "%d\n", numero1);
		f1 = fscanf(arq1, "%d", &numero1);
	}

	while(f2 != EOF) {
		fprintf(arqOut, "%d", numero2);
		f2 = fscanf(arq2, "%d", &numero2);
	}

	fclose(arq1);
	fclose(arq2);
	fclose(arqOut);

	return 0;
}
