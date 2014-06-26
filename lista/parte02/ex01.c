#include <stdio.h>

int main() {
	int a, b, c;

	printf("Digite o comprimento de três segmentos: ");
	scanf("%d %d %d", &a, &b, &c);

	if(a > b && a > c && a > b + c)
		printf("Não é triangulo.\n");
	else if(b > a && b > c && b > a + c)
		printf("Não é triangulo.\n");
	else if(c > a + b)
		printf("Não é triangulo.\n");
	else {
		if(a != b && b != c && a != c)
			printf("É triangulo escaleno.\n");
		else if(a == b && b == c && c == a)
			printf("É triangulo equilátero.\n");
		else
			printf("É triangulo isosceles.\n");
	}

	return 0;
}
