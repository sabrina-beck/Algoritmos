#include <stdio.h>

int mult(int a, int b);

int main() {
	int a, b;

	printf("Digite dois valores: ");
	scanf("%d %d", &a, &b);

	printf("Multiplicação: %d\n", mult(a, b));

	return 0;
}

int mult(int a, int b) {
	if(b == 0)
		return 0;
	return a + mult(a, --b);
}
