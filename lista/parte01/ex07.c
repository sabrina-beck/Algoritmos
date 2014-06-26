#include <stdio.h>

int main() {
	int a, b;

	printf("Digite dois números inteiros: ");
	scanf("%d %d", &a, &b);

	printf("Antes - a: %d, b: %d\n", a, b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("Depois - a: %d, b: %d\n", a, b);	

	return 0;
}
