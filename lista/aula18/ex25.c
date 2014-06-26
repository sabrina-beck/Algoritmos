#include <stdio.h>

int ocorrencias(char *str, char c);

int main() {
	char str[100];
	char c;

	printf("Digite uma frase: ");
	scanf("%[^\n]", str);

	printf("Digite um caracter: ");
	scanf(" %c", &c);

	printf("Ocorrencias de %c: %d\n", c, ocorrencias(str, c));


	return 0;
}

int ocorrencias(char *str, char c) {
	if(*str == 0)
		return 0;
	if(*str == c)
		return ocorrencias(str + 1, c) + 1;
	return ocorrencias(str + 1, c);
}
