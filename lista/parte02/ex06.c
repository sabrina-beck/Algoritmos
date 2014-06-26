#include <stdio.h>

int main() {
	int a1, a2, b1, b2;
	float x, y;

	printf("Coeficientes da reta 1: ");
	scanf("%d %d", &a1, &b1);

	printf("Coeficientes da reta 2: ");
	scanf("%d %d", &a2, &b2);

	if(a1 != a2) {
		x = (float)(b2-b1) / (a1 - a2);
		y = a1*x + b1;
		printf("Se interceptam em (%.2f, %.2f).\n", x, y);
	} else
		printf("São paralelas, não se interceptam.\n");

	return 0;
}
