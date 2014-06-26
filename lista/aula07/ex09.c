#include <stdio.h>
#include <math.h>

int main() {
	int binario, decimal, i;

	printf("Digite um numero na base binária: ");
	scanf("%d", &binario);

	decimal = 0;
	for(i = 0; binario > 0; i++) {
		decimal += (binario % 10) * pow(2, i);
		binario /= 10;
	}

	printf("Equivale a %d na base decimal.\n", decimal);

	return 0;
}
