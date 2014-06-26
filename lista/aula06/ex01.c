#include <stdio.h>

int main() {
	int n, i;

	printf("Digite um valor inteiro positivo: ");
	scanf("%d", &n);

	printf("Divisores: ");
	for(i = 1; i <= n/2; i++) {
		if(n % i == 0)
			printf("%d ", i);
	}
	printf("%d\n", n);

	return 0;
}
