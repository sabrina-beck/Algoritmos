#include <stdio.h>

int main() {
	char cAtual;
	int soma = 0;

	printf("Digite uma frase: ");

	do {
		scanf("%c", &cAtual);
		if((cAtual >= 65 && cAtual <= 90) || (cAtual >= 97 && cAtual <= 122))
			soma++;
	} while(cAtual != '\n');

	printf("A frase digitada tem %d letras.\n", soma);

	return 0;
}
