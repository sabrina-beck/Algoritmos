#include <stdio.h>
#include <math.h>

#define PI 3.14

int main() {
	float raio, circunferencia, area;

	printf("Digite o raio da circunferência: ");
	scanf("%f", &raio);

	circunferencia = 2 * PI * raio;
	area = PI * pow(raio, 2);

	printf("Circunferência: %.2f\n", circunferencia);
	printf("Área: %.2f\n", area);

	return 0;
}
