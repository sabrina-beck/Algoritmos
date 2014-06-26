#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, delta, x1, x2;

	printf("Coeficientes: ");
	scanf("%f %f %f", &a, &b, &c);

	printf("[EQUAÇÃO] %.2fx² + %.2fx + %.2f\n", a, b, c);

	delta = pow(b, 2) - 4 * a * c;
	if(delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		printf("x1 = %.2f\n", x1);
		printf("x2 = %.2f\n", x2);
	} else if(delta == 0) {
		x1 = -b / (2 * a);
		printf("x = %.2f\n", x1);
	} else {
		delta *= -1;
		x1 = -b / (2 * a);
		x2 = sqrt(delta) / (2 * a);
		printf("x1 = %.2f + %.2fi\n", x1, x2);
		printf("x2 = %.2f - %.2fi\n", x1, x2);
	}

	return 0;
}
