#include <stdio.h>

int somaDigitos(int n);

int main() {
	int n;

	printf("Digite um valor: ");
	scanf("%d", &n);

	printf("Soma dos dígitos = %d\n", somaDigitos(n));

	return 0;
}

int somaDigitos(int n) {
	if(n >= 0 && n < 10)
		return n;
	return (n % 10) + somaDigitos(n / 10);
}
