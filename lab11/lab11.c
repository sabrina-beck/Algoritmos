#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_DO_NOME 71

/* Structs e Enums */
enum bool {
	false,
	true
}

typedef enum bool bool;

struct Data {
	unsigned short int dia;
	unsigned short int mes;
	unsigned short int ano;
}

typedef struct Data Data;

struct Aluno {
	char[TAMANHO_MAXIMO_DO_NOME];
	int ra;
	char genero;
	Data nascimento;
	char generoQueProcura;
	int *seguidores;
}

typedef struct Aluno Aluno;

/* Variáveis globais */
int n; /* quantidade de alunos a serem cadastrados */
Aluno *alunos;

/* Programa Principal */
int main() {

	/* Lê a quantidade de alunos a serem cadastrados */
	scanf("%d ", &n);

	/* Aloca o vetor de alunos */
	alunos = alocar(n);

	desalocar(alunos);

	return 0;
}


