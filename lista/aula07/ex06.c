#include <stdio.h>

int main() {
	int fator, n;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(fator = 2; fator <= n;) {
		if(n % fator == 0) {
			printf("\t%d\n", fator);
			n = n / fator;
		} else
			fator++;
	}

	return 0;
}
