#include <stdio.h>

int main() {
	char c;
	printf("Digite um caracter: \n");
	setbuf(stdin, 0);	
	scanf(" %c", &c);
	printf("O valor ascii de %c eh %d\n", c, c);
	return 0;
}
