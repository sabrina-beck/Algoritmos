#include <stdio.h>

int somaPares(int n);

int main() {
	int n;

	printf("Digite um valor: ");
	scanf("%d", &n);

	printf("Soma: %d\n", somaPares(n));

	return 0;
}

int somaPares(int n) {
	if(n == 0)
		return 0;
	if(n % 2 == 0)
		return n + somaPares(n-2);
	return somaPares(n-1);
}
