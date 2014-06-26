#include <stdio.h>
#include <math.h>

int main() {
	int cateto1, cateto2, hipotenusa;

	/* Leitura dos dados */
	printf("Digite os valores dos catetos: ");
	scanf("%d %d", &cateto1, &cateto2);

	/* Calculo da hipotenusa pelo teorema de pitagoras */
	hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

	/* Apresentacao dos dados calculados */
	printf("O valor da hipotenusa é: %d\n", hipotenusa);

	return 0;
}
