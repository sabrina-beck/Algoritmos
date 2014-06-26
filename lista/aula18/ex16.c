#include <stdio.h>

void strcp(char *s, char *t);

int main() {
	char s[100], t[100];

	printf("Digite uma frase: ");
	scanf("%[^\n]", t);

	strcp(s, t);

	printf("String s: %s\n", s);

	return 0;
}

void strcp(char *s, char *t) {
	*s = *t;
	if(*s)
		strcp(s + 1, t + 1);
}
