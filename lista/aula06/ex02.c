#include <stdio.h>

int main() {
	int n, i, cont;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(i = 1, cont = 0; i <= n/2; i++)
		if(n % i == 0)
			cont++;
	cont++;

	printf("%d tem %d divisores.\n", n, cont);

	return 0;
}
