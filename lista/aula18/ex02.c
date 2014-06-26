#include <stdio.h>

unsigned long int fatorial(unsigned short int n);

int main() {
	unsigned short int n;
	unsigned long int fat;

	printf("Digite um valor: ");
	scanf("%hu", &n);

	fat = fatorial(n);

	printf("%hu! = %lu\n", n, fat);

	return 0;
}

unsigned long int fatorial(unsigned short int n) {
	if(n == 0)
		return 1;
	return n * fatorial(n-1);
}
