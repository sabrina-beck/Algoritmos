#include <stdio.h>

int main() {
	int numero;

	printf("Digite um número: ");
	scanf("%d", &numero);

	if(numero / 10000 == 0 && numero % 10000 > 0) {
		int primeiro, segundo, terceiro, quarto;
		printf("%d tem 4 digitos.\n", numero);
		quarto = numero % 10;
		numero /= 10;
		terceiro = numero % 10;
		numero /= 10;
		segundo = numero % 10;
		numero /= 10;
		primeiro = numero % 10;
		if(primeiro + segundo == terceiro + quarto)
			printf("Atende a especificação.\n");
		else
			printf("Não atende a especificação.\n");
	} else
		printf("[ERRO] Mensagem inválida!\n");

	return 0;
}
