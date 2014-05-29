/**
 * Nome: Sabrina Beck Angelini
 * RA: 157240
 * 					Never Alone
 * Através da numerologia e astrologia procura um par 
 * compatível a um aluno solitário da Unicamp.
**/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOME 42
#define MAX_RA 8
#define TAMANHO_DATA 11
#define DIA 15
#define MES 5
#define ANO 2014

/*********************** Declarações ***********************/
enum boolean {
	false,
	true
};

typedef enum boolean bool;

struct Data {
	unsigned short int dia;
	unsigned short int mes;
	unsigned short int ano;
};

typedef struct Data Data;

struct Aluno {
	char nome[MAX_NOME];
	int ra;
	char genero;
	Data nascimento;
	char generoQueProcura;
	int loveNumber;
	double loveRate;
};

typedef struct Aluno Aluno;

int n; /** quantidade de alunos na turma **/
Aluno *turma;
int solitario; /** posição do aluno solitario **/
int diffMax;

int getAnoDoRA(int ra){
	return ra / 10000;
}

int tamanhoDoPrimeiroNome(char nome[]) {
	int i;

	for(i = 0; nome[i] != '\0' && nome[i] != '\n' && nome[i] != ' '; i++);

	return i;
}

/**
 * Verifica se a data já passou
**/
bool jaPassou(Data data) {
	return MES > data.mes || (MES == data.mes && DIA >= data.dia);
}

int calculaIdade(Data nascimento) {
	int idade = ANO - nascimento.ano;
	if(!jaPassou(nascimento))
		idade--;
	return idade;
}

int arredonda(double x) {
	if (x < 0.0)
		return (int)(x - 0.5);
	else
		return (int)(x + 0.5);
}

int modulo(int a) {
	if(a < 0)
		return -a;
	return a;
}

int loveNumber(Aluno aluno) {
	int qntCaracteres = tamanhoDoPrimeiroNome(aluno.nome);
	int nascDia = aluno.nascimento.dia;
	int nascMes = aluno.nascimento.mes;
	int raAno = getAnoDoRA(aluno.ra);
	return arredonda(sqrt(qntCaracteres * (nascDia + nascMes))) + raAno;
}

double loveRate(Aluno a, Aluno b) {
	if(a.genero != b.generoQueProcura || b.genero != a.generoQueProcura)
		return 0.0;

	return 1 - (double) modulo(a.loveNumber - b.loveNumber) / (double) diffMax;
}

Aluno parPerfeitoParaOSolitario() {
	int i, parPerfeito = -1;
	double maiorLoveRate;

	for(i = 0; i < n; i++) {
		if(i != solitario) {
			turma[i].loveRate = loveRate(turma[solitario], turma[i]);
			if(parPerfeito == -1 || maiorLoveRate < turma[i].loveRate) {
				maiorLoveRate = turma[i].loveRate;
				parPerfeito = i;
			}
		}

	}

	return turma[parPerfeito];
}

void lerLinha(char linha[], int tamanho) {
	setbuf(stdin, 0);
	fgets(linha, tamanho, stdin);
	
	while(linha[0] == '\n' && linha[1] == '\0') {
		setbuf(stdin, 0);
		fgets(linha, tamanho, stdin);
	}
}

/**
 * Lê uma data e armazena em um registro do tipo Data
**/
Data lerData() {
	char data[TAMANHO_DATA];
	Data date;
	char dia[3];
	char mes[3];
	char ano[5];
	
	lerLinha(data, TAMANHO_DATA);
	
	dia[0] = data[0];
	dia[1] = data[1];
	dia[2] = '\0';
	date.dia = atoi(dia);
	
	mes[0] = data[3];
	mes[1] = data[4];
	mes[2] = '\0';
	date.mes = atoi(mes);
	
	ano[0] = data[6];
	ano[1] = data[7];
	ano[2] = data[8];
	ano[3] = data[9];
	ano[4] = '\0';
	date.ano = atoi(ano);
	
	return date;
}

/**
 * Lê os dados de um aluno.
**/
Aluno lerAluno() {
	Aluno aluno;
	
	lerLinha(aluno.nome, MAX_NOME);
	
	scanf("%d", &aluno.ra);
/*	lerLinha(aluno.ra, MAX_RA);*/
	
	scanf(" %c", &aluno.genero);
	
	aluno.nascimento = lerData();
	
	scanf(" %c", &aluno.generoQueProcura);

	aluno.loveNumber = loveNumber(aluno);
	
	return aluno;
}

/**
 * Lê os alunos da turma e calcula a maior diferenca entre os loveNumbers dos alunos
**/
void lerTurma() {
	int i, maxLoveNumber, minLoveNumber;
	
	turma = (Aluno*) malloc(n * sizeof(Aluno));
	
	for(i = 0; i < n; i++) {
		turma[i] = lerAluno();

		if(i == 0 || (maxLoveNumber < turma[i].loveNumber))
			maxLoveNumber = turma[i].loveNumber;

		if(i == 0 || (minLoveNumber > turma[i].loveNumber))
			minLoveNumber = turma[i].loveNumber;
	}

	diffMax = maxLoveNumber - minLoveNumber;
}

void ler() {
	scanf("%d\n", &n); /** Lê a quantidade de alunos na turma **/
	
	lerTurma();
	
	scanf("\n%d", &solitario); /** Lê a posicao do aluno solitario **/
	solitario--;
}

void simbolo(char simbolo[], double compatibilidade) {
	simbolo[2] = '\0';
	if(compatibilidade < 0.5){
		simbolo[0] = ':';
		simbolo[1] = '(';
	} else if(compatibilidade >= 0.5 && compatibilidade < 0.9) {
		simbolo[0] = '<';
		simbolo[1] = '3';
	} else {
		simbolo[0] = 'S';
		simbolo[1] = '2';
	}
}

void tirarPuloDeLinha(char nome[]) {
	int i;
	for(i = 0; nome[i]; i++)
		if(nome[i] == '\n')
			nome[i] = '\0';
}

void escreveCasal(Aluno a, Aluno b) {
	char simbol[3];
	simbolo(simbol, b.loveRate);

	tirarPuloDeLinha(a.nome);
	tirarPuloDeLinha(b.nome);

	printf("%s %s %s ( %d%% )\n", a.nome, simbol, b.nome, (int)(b.loveRate*100));

	printf("%c %c\n", a.genero, b.genero);

	printf("%d anos %d anos\n", calculaIdade(a.nascimento), calculaIdade(b.nascimento));
}

int main() {
	Aluno parPerfeito;

	ler();

	parPerfeito = parPerfeitoParaOSolitario();

	escreveCasal(turma[solitario], parPerfeito);
	
	return 0;
}
