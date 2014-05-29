#include <stdio.h>

int main() {
	char comentario[71];
	fgets(comentario, 71, stdin);
	printf("\n[SAIDA] %s\n", comentario);
	return 0;
}
