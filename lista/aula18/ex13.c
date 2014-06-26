#include <stdio.h>

int strlen(char *str);

int main() {
	char str[100];

	printf("Digite uma frase: ");
	scanf("%[^\n]", str);

	printf("Tamanho da frase: %d\n", strlen(str));

	return 0;
}

int strlen(char *str) {
	if(str[0] == 0)
		return 0;
	return 1 + strlen(str + 1);
}
