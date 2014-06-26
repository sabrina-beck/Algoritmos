#include <stdio.h>

int main() {
	int a, b, c, d, e, f;
	float x, y;

	printf("Digite a primeira equação: ");
	scanf("%dx+%dy=%d", &a, &b, &c);
	printf("Digite a segunda equação: ");
	scanf("%dx+%dy=%d", &d, &e, &f);

	if((a*e - b*d) == 0)
		printf("Sistema impossível!");
	else {
		x = (float)(c*e - b*f) / (a*e - b*d);
		y = (float)(a*f - c*d) / (a*e - b*d);
		printf("x = %.2f\ny = %.2f\n", x, y);
	}

	return 0;
}
