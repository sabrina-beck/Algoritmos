#include <stdio.h>

int soma(int a, int b);

int main() {
	int a, b;

	printf("Digite dois valores: ");
	scanf("%d %d", &a, &b);

	printf("Soma: %d\n", soma(a, b));

	return 0;
}

int soma(int a, int b) {
	if(b == 0)
		return a;
	return soma(++a, --b);
}
