#include <stdio.h>

int prod(int m, int n);

int main() {
	int m, n;

	printf("Digite dois valores: ");
	scanf("%d %d", &m, &n);

	printf("Produtorio de %d até %d é %d\n", m, n, prod(m, n));

	return 0;
}

int prod(int m, int n) {
	if(m == n)
		return n;
	return m * prod(m + 1, n);
}
