#include <stdio.h>

int main() {
	FILE *arq1, *arq2, *arqOut;
	char nome1[100], nome2[100], nome3[100];
	int numero1, numero2, continua1, continua2;

	printf("Qual o nome do primeiro arquivo de entrada? ");
	scanf("%s", nome1);
	arq1 = fopen(nome1, "rb");

	if(arq1 == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nome1);
		return 0;
	}

	printf("Qual o nome do segundo arquivo de entrada? ");
	scanf("%s", nome2);
	arq2 = fopen(nome2, "rb");

	if(arq2 == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nome2);
		fclose(arq1);
		return 0;
	}

	printf("Qual o nome do arquivo de destino? ");
	scanf("%s", nome3);
	arqOut = fopen(nome3, "wb");

	if(arqOut == NULL) {
		printf("Erro ao abrir o arquivo %s para escrita.", nome3);
		fclose(arq1);
		fclose(arq2);
		return 0;
	}

	continua1 = fread(&numero1, sizeof(int), 1, arq1);
	continua2 = fread(&numero2, sizeof(int), 1, arq2);

	while(continua1 && continua2) {
		if(numero1 < numero2) {
			fwrite(&numero1, sizeof(int), 1, arqOut);
			continua1 = fread(&numero1, sizeof(int), 1, arq1);
		} else {
			fwrite(&numero2, sizeof(int), 1, arqOut);
			continua2 = fread(&numero2, sizeof(int), 1, arq2);
		}
	}

	while(continua1) {
		fwrite(&numero1, sizeof(int), 1, arqOut);
		continua1 = fread(&numero1, sizeof(int), 1, arq1);
	}

	while(continua2) {
		fwrite(&numero2, sizeof(int), 1, arqOut);
		continua2 = fread(&numero2, sizeof(int), 1, arq2);
	}

	fclose(arq1);
	fclose(arq2);
	fclose(arqOut);

	arqOut = fopen(nome3, "rb");

	if(arqOut == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nome3);
		return 0;
	}

	while(fread(&numero1, sizeof(int), 1, arqOut))
		printf("%d\n", numero1);

	fclose(arqOut);

	return 0;
}
