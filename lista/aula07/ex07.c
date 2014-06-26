#include <stdio.h>

int main() {
	int n, primeiro = 1, segundo = 1, i;

	printf("Digite um valor: ");
	scanf("%d", &n);

	printf("Fibonacci: ");

	if(n >= 1)
		printf("%d ", primeiro);
	if(n >= 2)
		printf("%d ", segundo);

	for(i = 2; i < n; i++) {
		int aux = segundo;
		segundo = primeiro + segundo;
		primeiro = aux;
		printf("%d ", segundo);
	}

	printf("\n");

	return 0;
}
