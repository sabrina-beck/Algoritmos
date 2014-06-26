#include <stdio.h>
#include <math.h>

unsigned long int fatorial(int n) {
	int i;
	unsigned long int fat = 1;

	for(i = 1; i <= n; i++)
		fat *= i;

	return fat;
}

/*FIXME*/
int main() {
	int x, k, i, fat, sinal = -1;
	float cos = 1;

	printf("Digite um valor em radianos: ");
	scanf("%d", &x);

	printf("Digite quantos termos desejados: ");
	scanf("%d", &k);

	fat = 2;
	for(i = 1; i < k; i++) {
		cos += (pow(x, fat) / fatorial(fat)) * sinal;
		fat += 2;
		sinal *= -1;
	}

	printf("cos %d = %.6f\n", x, cos);

	return 0;
}
