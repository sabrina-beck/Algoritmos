#include <stdio.h>

int main() {
	int n, i, soma = 0;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(i = 1; i <= n/2; i++)
		if(n % i == 0)
			soma += i;

	if(soma == n)
		printf("É perfeito.\n");
	else
		printf("Não é perfeito.\n");

	return 0;
}
