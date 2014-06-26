#include <stdio.h>

int somaPrimeirosInteiros(int n) {
	if(n == 1)
		return 1;
	return n + somaPrimeirosInteiros(n-1);
}

int main() {
	int n, soma;

	printf("Digite um valor: ");
	scanf("%d", &n);

	soma = somaPrimeirosInteiros(n);

	printf("A soma dos %d primeiros inteiros é %d.\n", n, soma);

	return 0;
}
