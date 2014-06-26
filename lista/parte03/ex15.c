#include <stdio.h>

int main() {
	int y;
	float x, resultado = 1;

	printf("Digite o expoente: ");
	scanf("%d", &y);

	printf("Digite a base: ");
	scanf("%f", &x);

	if(y > 0) {
		int i;
		for(i = 0; i < y; i++)
			resultado *= x;
	} else if(y < 0) {
		int i;
		for(i = 0; i < -y; i++)
			resultado *= (float) 1 / x;
	}

	printf("%.2f^%d = %.2f\n", x, y, resultado);

	return 0;
}
