#include <stdio.h>

int main() {
	int opcao;

	do {
		printf("O que deseja?\n");
		printf("1. Almondegas\n");
		printf("2. Canja de Galinha\n");
		printf("3. Banana Split\n");
		printf("4. Lasanha a Bolonhesa\n");
		printf("5. Sair\n");
		printf("Digite sua opção: ");
		scanf("%d", &opcao);

		switch(opcao) {
			case 1: {
				printf("Bolas de carne.\n");
			}
			break;
			case 2: {
				printf("Sopa com arroz e frango.\n");
			}
			break;
			case 3: {
				printf("Banana com sorvete.\n");
			}
			break;
			case 4: {
				printf("Massa com presunto, queijo, molho de tomate e molho branco.\n");
			}
		}
	} while(opcao != 5);

	return 0;
}
