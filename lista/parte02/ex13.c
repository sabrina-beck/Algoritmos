#include <stdio.h>

int main() {
	char nome[101];
	int idade;

	printf("Qual o nome do nadador? ");
	scanf("%[^\n]", nome);

	printf("Qual a idade do nadador? ");
	scanf(" %d", &idade);

	printf("Nome: %s\n", nome);
	printf("Idade: %d\n", idade);

	printf("Categoria: ");
	if(idade <= 10)
		printf("Infantil 1.\n");
	else if(idade <= 12)
		printf("Infantil 2.\n");
	else if(idade <= 16)
		printf("Juvenil.\n");
	else if(idade <= 19)
		printf("Junior.\n");
	else if(idade <= 25)
		printf("Senior.\n");
	else
		printf("Master.\n");

	return 0;
}
