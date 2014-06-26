#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, x1, x2, delta;

	printf("Digite as constantes de uma equação de segundo grau: ");
	scanf("%f %f %f", &a, &b, &c);

	printf("A equação: %fx^2 + %fx + %f\n", a, b, c);

	delta = pow(b, 2) - 4 * a * c;
	if(delta < 0) {
		printf("Não tem solução!\n");
	} else {
		x1 = (-b + sqrt(delta)) / (2.0 * a);
		if(delta == 0)
			printf("x = %.2f\n", x1);
		else {
			x2 = (-b - sqrt(delta)) / (2.0 * a);
			printf("x1 = %.2f\n", x1);
			printf("x2 = %.2f\n", x2);
		}
	}	

	return 0;
}
