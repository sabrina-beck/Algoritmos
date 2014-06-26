#include <stdio.h>

int strcmp(char *str1, char *str2);

int main() {
	char str1[100], str2[100];

	printf("Digite uma frase: ");
	scanf("%[^\n]", str1);

	printf("Digite uma frase: ");
	scanf(" %[^\n]", str2);

	printf("Comparação retornou %d.\n", strcmp(str1, str2));

	return 0;
}

int strcmp(char *str1, char *str2) {
	if(*str1 != *str2 || *str1 == 0)
		return *str1 - *str2;
	return strcmp(str1 + 1, str2 + 1);
}
