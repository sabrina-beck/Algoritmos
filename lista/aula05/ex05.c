#include <stdio.h>
#include <math.h>

enum bool {
	false,
	true
};

typedef enum bool bool;

bool pitagoras(int hipotenusa, int cateto1, int cateto2) {
	return pow(hipotenusa, 2) == pow(cateto1, 2) + pow(cateto2, 2);
}

int main() {
	int a, b, c;

	printf("Digite o comprimento de tres segmentos: ");
	scanf("%d %d %d", &a, &b, &c);

	if((a > b && a > c && pitagoras(a, b, c)) ||
	   (b > a && b > c && pitagoras(b, a, c)) ||
	   (c > a && c > b && pitagoras(a, b, a)))
		printf("É triangulo retangulo.\n");
	else
		printf("Não é triangulo retangulo.\n");

	return 0;
}
