#include <stdio.h>

enum bool {
	false,
	true
};

typedef enum bool bool;

int quantidadeDeDigitos(int numero) {
	int digitos;
	for(digitos = 0; numero != 0; digitos++)
		numero /= 10;
	return digitos;
}

int inverte(int numero) {
	int invertido = 0;
	while(numero != 0) {
		invertido *= 10;
		invertido += numero % 10;
		numero /= 10;
	}
	return invertido;
}

bool ehPalindromo(int numero) {
	return numero == inverte(numero);
}

int main() {
	int numero;

	printf("Digite um número: ");
	scanf("%d", &numero);

	printf("Quantidade de digitos: %d\n", quantidadeDeDigitos(numero));

	printf("Invertido: %d\n", inverte(numero));

	if(ehPalindromo(numero))
		printf("É palindromo!\n");
	else
		printf("Não é palindromo!\n");

	return 0;
}
