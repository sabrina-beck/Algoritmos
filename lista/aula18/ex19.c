#include <stdio.h>

void hanoi(int n, char inicial, char final, char auxiliar);

int main() {
	int n;

	printf("Quantos discos serão movidos? ");
	scanf("%d", &n);

	hanoi(n, 'A', 'C', 'B');

	return 0;
}

void hanoi(int n, char inicial, char final, char auxiliar) {
	if(n == 1)
		printf("Mova o disco %d de %c para %c.\n", n, inicial, final);
	else {
		hanoi(n - 1, inicial, auxiliar, final);
		printf("Mova o disco %d de %c para %c.\n", n, inicial, final);
		hanoi(n - 1, auxiliar, final, inicial);
	}
}
