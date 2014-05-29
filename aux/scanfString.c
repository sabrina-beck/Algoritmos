#include <stdio.h>

int main() {
	char string[10];
	char test;
	scanf(" %c ", &test);
	scanf("%[^\n]s", string);
	printf("%s", string);
	return 0;
}
