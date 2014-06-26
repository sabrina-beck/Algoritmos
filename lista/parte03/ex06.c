#include <stdio.h>

int main() {
	int base, numero, cont = 1, resultado = 0;

	printf("Qual o numero a ser convertido? ");
	scanf("%d", &numero);

	printf("Qual a base desejada? ");
	scanf("%d", &base);

	if(base < 2 || base > 9)
		return 0;

	while(numero > 0) {
		resultado += (numero % base) * cont;
		numero /= base;
		cont *= 10;
	}

	printf("%d\n", resultado);

	return 0;
}
