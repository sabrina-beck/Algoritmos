#include <stdio.h>

int main() {
	float celsius, fahrenheit, kelvin;
	int opcao;

	printf("Digite uma temperatura em graus celsius: ");
	scanf("%f", &celsius);

	printf("Em qual escala você deseja o resultado?\n");
	printf("1.Fahrenheit\n");
	printf("2.Kelvin\n");
	printf("3.Fahrenheit e Kelvin\n");
	printf("Digite o número da sua opção: ");
	scanf("%d", &opcao);

	fahrenheit = (9/5) * celsius + 32;
	kelvin = celsius + 273;

	if(opcao == 1 || opcao == 3)
		printf("Fahrenheit: %.2f\n", fahrenheit);

	if(opcao == 2 || opcao == 3)
		printf("Kelvin: %.2f\n", kelvin);

	printf("Bye!\n");

	return 0;
}
