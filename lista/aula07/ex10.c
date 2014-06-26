#include <stdio.h>

int main() {
	int decimal, binario, cont = 1;

	printf("Digite um numero na base decimal: ");
	scanf("%d", &decimal);

	binario = 0;
	while(decimal > 0) {
		binario += (decimal % 2) * cont;
		decimal /= 2;
		cont *= 10;
	}

	printf("Equivale a %d em binário.\n", binario);

	return 0;
}
