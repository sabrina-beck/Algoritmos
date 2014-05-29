#include <stdio.h>

#define CADASTRO 'c'
#define BUSCA 'b'
#define TAM_NOME_ALUNO 72
#define TAM_NOME_ARQUIVO 20

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

char nomeArquivo[TAM_NOME_ARQUIVO];
int n;
Aluno *alunos; /* FIXME tirar isso */
int alunoProcurado;


int main() {

	return 0;
}

void lerData(Data *data) {
	scanf("%hu/%hu/%hu", &data->dia, &data->mes, &data->ano);
}

void lerAluno(Aluno *aluno) {
	scanf("%[^\n]s", aluno->nome);
	scanf("%d", &aluno->ra);
	scanf(" %c", &aluno->genero);
	lerData(&aluno->nascimento);
	scanf(" %c", &aluno->generoQueProcura);
}

void lerAlunos() {
	int i;
	for(i = 0; i < n; i++)
		lerAluno(&alunos[i]);
}

void lerCadastro() {
	scanf("%[^\n]s", nomeArquivo);
	scanf(" %d", &n);

	lerAlunos();
}

void lerBusca() {
	scanf("%[^\n]s", nomeArquivo);
	scanf("%d", &alunoProcurado);
}

void ler() {
	char tipoEntrada;
	scanf(" %c", &tipoEntrada);

	if(tipoEntrada == CADASTRO)
		lerCadastro();
	else if(tipoEntrada == BUSCA)
		lerBusca();
}