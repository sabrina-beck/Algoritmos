#include <stdio.h>

int main() {
	float a, b, c;

	printf("Digite tres valores: ");
	scanf("%f %f %f", &a, &b, &c);

	printf("Valores: %.2f %.2f %.2f\n", a, b, c);

	if(a < b && a < c)
		printf("Menor: %.2f\n", a);
	else if(b < a && b < c)
		printf("Menor: %.2f\n", b);
	else
		printf("Menor: %.2f\n", c);

	if(a > b && a > c)
		printf("Maior: %.2f\n", a);
	else if(b > a && b > c)
		printf("Maior: %.2f\n", b);
	else
		printf("Maior: %.2f\n", c);

	return 0;
}
