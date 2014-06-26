#include <stdio.h>

enum bool {
	false, true
};

typedef enum bool bool;

bool palindromo(char *s, int n);

int main() {
	char str[100];
	int tam;

	printf("Digite uma frase: ");
	scanf("%[^\n]", str);

	for(tam = 0; str[tam]; tam++);

	if(palindromo(str, tam))
		printf("É palindromo!\n");
	else
		printf("Não é palindromo!\n");

	return 0;
}

bool palindromo(char *s, int n) {
	if(*s == 0)
		return true;
	if(s[0] != s[n-1])
		return false;
	return palindromo(s + 1, n - 2);
}
