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
void gerarChave(Aluno aluno, int chave[2][2]);

char nomeArquivo[TAM_NOME_ARQUIVO];
int n;
int alunoProcurado;
char tipoEntrada; /* FIXME verificar se deve mesmo ser global */


int main() {
/*	ler();
	escrever();*/
	int i, j;
	int chave[2][2];
	Aluno aluno;
	aluno.nascimento.dia = 22;
	aluno.nascimento.mes = 12;
	aluno.nascimento.ano = 1996;
	gerarChave(aluno, chave);

	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++)
			printf("%d ", chave[i][j]);
		printf("\n");
	}

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

void escreverData(Data data) {
	printf("Data Nascimento: %hu/%hu/%hu\n", data.dia, data.mes, data.ano);
}

void escreverAluno(Aluno aluno) {
		printf("Nome: %s\n", aluno.nome);
		printf("RA: %d\n", aluno.ra);
		printf("Genero: %c\n", aluno.genero);
		escreverData(aluno.nascimento);
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

void gerarChave(Aluno aluno, int chave[2][2]) {
	chave[0][0] = (aluno.nascimento.ano / 1000) * ((aluno.nascimento.ano % 1000) / 100);
	chave[0][1] = (aluno.nascimento.mes / 10) * (aluno.nascimento.mes % 10);
	chave[1][0] = (aluno.nascimento.dia / 10) * (aluno.nascimento.dia % 10);
	chave[1][1] = ((aluno.nascimento.ano % 100) / 10) * (aluno.nascimento.ano % 10);
}
