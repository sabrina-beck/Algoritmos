#include <stdio.h>

struct Coordenada {
	int x;
	int y;
};

typedef struct Coordenada Coordenada;

int main() {
	Coordenada coord;

	printf("Digite a coordenada a ser analisada: ");
	scanf("%d %d", &coord.x, &coord.y);

	if(coord.x == 0 && coord.y == 0)
		printf("Origem.\n");
	else if(coord.x == 0)
		printf("Eixo das ordenadas.\n");
	else if(coord.y == 0)
		printf("Eixo das abscissas.\n");
	else if(coord.x > 0) {
		if(coord.y > 0)
			printf("1º Quadrante.\n");
		else
			printf("4º Quadrante.\n");
	} else {
		if(coord.y > 0)
			printf("2º Quadrante.\n");
		else
			printf("3º Quadrante.\n");
	}

	return 0;
}
