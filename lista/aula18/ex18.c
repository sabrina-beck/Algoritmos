#include <stdio.h>

void imprimeInversa(char *s);

int main() {
	char str[100];

	printf("Digite uma frase: ");
	scanf("%[^\n]", str);

	imprimeInversa(str);

	printf("\n");

	return 0;
}

void imprimeInversa(char *s) {
	if(*s != 0) {
		imprimeInversa(s + 1);
		printf("%c", *s);
	}
}
