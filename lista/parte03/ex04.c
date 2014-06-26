#include <stdio.h>

int main() {
	int n, soma = 0, i;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(i = 1; i <= n/2; i++)
		if(n % i == 0)
			soma += i;

	soma += n;

	printf("Soma dos divisores = %d\n", soma);

	return 0;
}
