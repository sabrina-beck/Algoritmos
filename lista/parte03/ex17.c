#include <stdio.h>

int main() {
	float resistencia, resistenciaEquivalente = 0.0;

	do {
		printf("Digite o valor de uma resistencia: ");
		scanf("%f", &resistencia);

		if(resistencia != 0.0)
			resistenciaEquivalente += 1 / resistencia;
	} while(resistencia != 0);

	resistenciaEquivalente = 1 / resistenciaEquivalente;

	printf("Resistencia equivalente = %.2f\n", resistenciaEquivalente);

	return 0;
}
