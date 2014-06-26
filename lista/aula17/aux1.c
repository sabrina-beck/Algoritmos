#include <stdio.h>

int main() {
	FILE *arq;
	char nome[100];
	int num;

	printf("Qual o nome do arquivo? ");
	scanf("%s", nome);

	arq = fopen(nome, "wb");

	if(arq == NULL) {
		printf("Erro ao abrir o arquivo %s para leitura.\n", nome);
		return 0;
	}

	do {
		printf("Digite um valor: ");
		scanf("%d", &num);
		if(num != 0)
			fwrite(&num, sizeof(int), 1, arq);
	} while(num != 0);

	fclose(arq);

	arq = fopen(nome, "rb");

	if(arq == NULL) {
		printf("Erro ao abrir o arquivo %s para escrita.\n", nome);
		return 0;
	}

	while(fread(&num, sizeof(int), 1, arq))
		printf("%d\n", num);
	fclose(arq);

	return 0;
}
