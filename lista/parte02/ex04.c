#include <stdio.h>
#include <math.h>

int main() {
	float peso, altura, imc;

	printf("Digite seu peso e sua altura, respectivamente: ");
	scanf("%f %f", &peso, &altura);

	imc = (float) peso / pow(altura, 2);

	if(imc < 18.5)
		printf("Abaixo do peso.\n");
	else if(imc >= 18.5 && imc < 25.0)
		printf("Peso normal.\n");
	else if(imc >= 25.0 && imc < 30.0)
		printf("Sobrepeso.\n");
	else if(imc >= 30.0 && imc < 35.0)
		printf("Obesidade grau I.\n");
	else if(imc >= 35.0 && imc < 40.0)
		printf("Obesidade grau II.\n");
	else if(imc >= 40.0)
		printf("Obesidade grau III.");

	return 0;
}
