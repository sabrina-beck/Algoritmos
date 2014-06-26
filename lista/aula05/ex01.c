#include <stdio.h>

int main() {
	int a, b, c;

	printf("Digite tre valores: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Menor: ");
	if(a < b && a < c)
		printf("%d\n", a);
	else if(b < a && b < c)
		printf("%d\n", b);
	else
		printf("%d\n", c);

	return 0;
}
