#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_DO_NOME 71

/* Structs e Enums */
enum bool {
	false,
	true
};

typedef enum bool bool;

struct Data {
	unsigned short int dia;
	unsigned short int mes;
	unsigned short int ano;
};

typedef struct Data Data;

struct Aluno {
	char nome[TAMANHO_MAXIMO_DO_NOME];
	int ra;
	char genero;
	Data nascimento;
	char generoQueProcura;
	int *seguidores;
	int qtdSeguidores;
};

typedef struct Aluno Aluno;

/* Funções (Declaração) */
void lerAlunos(Aluno alunos[], int n);
Aluno lerAluno(int n);
Data lerData();
int* lerSeguidores(int n, int *qtdSeguidores);
void escreverAlunos(Aluno alunos[], int n); /* FIXME [TRASH] */
void escreverAluno(Aluno aluno); /* FIXME [TRASH] */
void escreverData(Data data); /* FIXME [TRASH] */
void escreverSeguidores(int seguidores[], int qtd); /* FIXME [TRASH] */

/* Variáveis globais */

/* Programa Principal */
int main() {
	int n; /* quantidade de alunos a serem cadastrados */
	Aluno *alunos;
	int s; /* indice do aluno cuja popularidade é requisitada */

	/* Lê a quantidade de alunos a serem cadastrados */
	scanf("%d ", &n);

	/* Aloca o vetor de alunos */
	alunos = (Aluno*) malloc(n * sizeof(Aluno));

	lerAlunos(alunos, n);

	/* Lê linha em branco */
	scanf("\n");

	/* Lê o indice do aluno cuja popularidade é requisitada */
	scanf("%d ", &s);
	s--;

	/* FIXME [TRASH] verificação da entrada */
	/*printf("%d\n", n);
	escreverAlunos(alunos, n);
	printf("\n%d\n", s+1);*/

	/* Desaloca o vetor de alunos */
	/* TODO free nos seguidores */
	free(alunos);

	return 0;
}

/*
 * Lê os alunos que serão cadastrados
 */
void lerAlunos(Aluno alunos[], int n) {
	int i;

	for(i = 0; i < n; i++)
		alunos[i] = lerAluno(n);
}

/*
 * Lê um Aluno
 */
Aluno lerAluno(int n) {
	Aluno aluno;

	/* Lê o nome do aluno */
	scanf("%[^\n]s", aluno.nome);

	/* Lê o ra do aluno */
	scanf("%d ", &aluno.ra);

	/* Lê o genero do aluno */
	scanf("%c ", &aluno.genero);

	/* Lê a data de nascimento do aluno */
	aluno.nascimento = lerData();

	/* Lê o genero que o aluno procura */
	scanf("%c ", &aluno.generoQueProcura);

	/* Lê a lista de seguidores do aluno */
	aluno.seguidores = lerSeguidores(n, &aluno.qtdSeguidores);

	return aluno;
}

/*
 * Lê uma data no formato dd/mm/aaaa
 */
Data lerData() {
	Data data;
	scanf("%hu/%hu/%hu ", &data.dia, &data.mes, &data.ano);
	return data;
}

/*
 * Lê uma lista de seguidores terminada em 0
 */
int* lerSeguidores(int n, int *qtdSeguidores) {
	int valorLido = 1, i;
	int *seguidores, *aux;
	*qtdSeguidores = 0;

	/* Aloca o vetor de seguidores com tamanho sendo o máximo de seguidores possíveis */
	seguidores = (int*) malloc(n * sizeof(int));

	/* Lê a lista de seguidores */
	for(*qtdSeguidores = 0; valorLido != 0; (*qtdSeguidores)++) {
		scanf("%d ", &valorLido);		
		seguidores[*qtdSeguidores] = valorLido;
	}

	/* Acerta o tamanho do vetor */
	(*qtdSeguidores)--;
	aux = (int*) malloc((*qtdSeguidores) * sizeof(int));
	for(i = 0; i < *qtdSeguidores; i++)
		aux[i] = seguidores[i] - 1; /* guarda o índice dos seguidores */
	free(seguidores);
	return aux;
}

/*
 * FIXME [TRASH]
 */
void escreverAlunos(Aluno alunos[], int n){
	int j;
	for(j = 0; j < n; j++)
		escreverAluno(alunos[j]);
}

/*
 * FIXME [TRASH]
 */
void escreverAluno(Aluno aluno) {
	printf("%s\n", aluno.nome);
	printf("%d\n", aluno.ra);
	printf("%c\n", aluno.genero);
	escreverData(aluno.nascimento);
	printf("%c\n", aluno.generoQueProcura);
	escreverSeguidores(aluno.seguidores, aluno.qtdSeguidores);
}

/*
 * FIXME [TRASH]
 */
void escreverData(Data data) {
	printf("%2hu/%2hu/%4hu\n", data.dia, data.mes, data.ano);
}

/*
 * FIXME [TRASH]
 */
void escreverSeguidores(int seguidores[], int qtd) {
	int i;
	for(i = 0; i < qtd; i++)
		printf("%d ", seguidores[i] + 1);
	printf("0\n");
}
