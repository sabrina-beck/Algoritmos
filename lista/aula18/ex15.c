#include <stdio.h>

char* strch(char *str, char c);

int main() {
	char str[100];
	char c, *res;

	printf("Digite uma frase: ");
	scanf("%[^\n]", str);

	printf("Qual o caracter procurado? ");
	scanf(" %c", &c);

	res = strch(str, c);

	if(res == NULL)
		printf("Não achou!\n");
	else
		printf("Achou %c.\n", *res);

	return 0;
}

char* strch(char *str, char c) {
	if(*str == 0)
		return NULL;	
	if(*str == c)
		return str;
	return strch(str + 1, c);
}
