#include <stdio.h>

void binarioDe(int n);

int main() {
	int n;

	printf("Digite um valor: ");
	scanf("%d", &n);

	binarioDe(n);

	printf("\n");

	return 0;
}

void binarioDe(int n) {
	if(n != 0) {
		binarioDe(n/2);
		printf("%d", n % 2);
	}
}
