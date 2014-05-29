#include <stdio.h>

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
int alunoProcurado;
char tipoEntrada; /* FIXME verificar se deve mesmo ser global */


int main() {
	ler();
	escrever();
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

void escreverAluno(Aluno aluno) {
		printf("Nome: %s\n", aluno.nome);
		printf("RA: %d\n", aluno.ra);
		printf("Genero: %c\n", aluno.genero);
		printf("Data Nascimento: %hu/%hu/%hu\n", aluno.nascimento.dia, aluno.nascimento.mes, aluno.nascimento.ano);
		printf("Genero que procura: %c\n\n", aluno.generoQueProcura);
}

void escreverCadastro() { /* FIXME tirar isso */
	FILE* baseDeDados = fopen(nomeArquivo, "rb");
	int i;

	for(i = 0; i < n; i++) {
		Aluno aluno;
		fread(&aluno, sizeof(Aluno), 1, baseDeDados);		
		escreverAluno(aluno);
	}
	fclose(baseDeDados);
}

void escreverBusca() { /* FIXME adaptar para a criptografia */
	FILE* baseDeDados = fopen(nomeArquivo, "rb");
	Aluno aluno;
	fseek(baseDeDados, (alunoProcurado - 1) * sizeof(Aluno), SEEK_SET);
	fread(&aluno, sizeof(Aluno), 1, baseDeDados);
	escreverAluno(aluno);
}

void escrever() { /* FIXME tirar isso */
	if(tipoEntrada == CADASTRO)
		escreverCadastro();
	else
		escreverBusca();
}
