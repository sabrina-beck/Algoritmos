#include <stdio.h>

int main() {
	int m, n;

	printf("Digites dois valores: ");
	scanf("%d %d", &m, &n);

	while(n != 0) {
		int aux = m;
		m = n;
		n = aux % n;
	}

	printf("MDC: %d\n", m);

	return 0;
}
