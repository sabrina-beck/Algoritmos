#include <stdio.h>

int fibonacci(int n);

int main() {
	int n;

	printf("Digite um valor: ");
	scanf("%d", &n);

	printf("%dº numero da série de fibonacci é: %d\n", n, fibonacci(n));

	return 0;
}

int fibonacci(int n) {
	if(n == 1 || n == 2)
		return 1;
	return fibonacci(n-2) + fibonacci(n-1);
}
