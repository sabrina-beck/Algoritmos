#include <stdio.h>
#include <stdlib.h>
/* FIXME tirar */

#define CADASTRO 'c'
#define BUSCA 'b'
#define TAM_NOME_ALUNO 72
#define TAM_NOME_ARQUIVO 100

struct Data {
	unsigned short int dia;
	unsigned short int mes;
	unsigned short int ano;
};

typedef struct Data Data;

struct Aluno {
	char nome[TAM_NOME_ALUNO];
	char genero;
	int ra;
	Data nascimento;
	char generoQueProcura;
};

typedef struct Aluno Aluno;

void ler();
void lerCadastro();
void lerBusca();
void escrever();

char nomeArquivo[TAM_NOME_ARQUIVO];
int n;
Aluno *alunos; /* FIXME tirar isso */
int alunoProcurado;
char tipoEntrada; /* FIXME verificar se deve mesmo ser global */


int main() {
	ler();
	escrever();
/*	free(alunos);*/ /* FIXME tirar isso */
	return 0;
}

void lerArquivo() { /* FIXME tirar isso */

}

void lerData(Data *data) {
	scanf("%hu/%hu/%hu ", &data->dia, &data->mes, &data->ano);
}

void lerAluno(Aluno *aluno) {
	scanf("%[^\n]s", aluno->nome);
	scanf("%d ", &aluno->ra);
	scanf(" %c ", &aluno->genero);
	lerData(&aluno->nascimento);
	scanf(" %c ", &aluno->generoQueProcura);
}

void cadastrarAlunos() {
	int i;	
	FILE* baseDeDados = fopen(nomeArquivo, "w+b");

	for(i = 0; i < n; i++) {
		Aluno aluno;
		lerAluno(&aluno);
		fwrite(&aluno, sizeof(Aluno), 1, baseDeDados);
	}

	fclose(baseDeDados);
}

void lerCadastro() {
	scanf("%[^\n]s", nomeArquivo);
	scanf(" %d ", &n);

	cadastrarAlunos();
}

void lerBusca() {
	scanf("%[^\n]s", nomeArquivo);
	scanf("%d ", &alunoProcurado);
}

void ler() {
	scanf(" %c ", &tipoEntrada);

	if(tipoEntrada == CADASTRO)
		lerCadastro();
	else if(tipoEntrada == BUSCA)
		lerBusca();
}



void escreverCadastro() { /* FIXME tirar isso */
	int i;
	printf("Arquivo: %s\n", nomeArquivo);
	printf("Qtd alunos: %d\n", n);
	printf("Alunos\n-----------------------\n");

	for(i = 0; i < n; i++) {
		printf("Nome: %s\n", alunos[i].nome);
		printf("RA: %d\n", alunos[i].ra);
		printf("Genero: %c\n", alunos[i].genero);
		printf("Data Nascimento: %hu/%hu/%hu\n", alunos[i].nascimento.dia, alunos[i].nascimento.mes, alunos[i].nascimento.ano);
		printf("Genero que procura: %c\n\n", alunos[i].generoQueProcura);
	}
}

void escreverBusca() { /* FIXME tirar isso */
	printf("Arquivo: %s\naluno procurado: %d", nomeArquivo, alunoProcurado);
}

void escrever() { /* FIXME tirar isso */
	if(tipoEntrada == CADASTRO)
		escreverCadastro();
	else
		escreverBusca();
}
