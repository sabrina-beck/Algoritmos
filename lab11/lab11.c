#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO_DO_NOME 71
#define D 0.85
#define ETAPAS 10
#define DIA 19
#define MES 6
#define ANO 2014
/* D é o damping factor usado pelo instituto Never Forever Alone */

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
float popularidade(int t, Aluno aluno);
int quantidadeDePessoasQueSegue(int seguidor);
int idade(Data nascimento);
bool jaPassou(Data data);
void escreverAlunos(Aluno alunos[], int n); /* FIXME [TRASH] */
void escreverAluno(Aluno aluno); /* FIXME [TRASH] */
void escreverData(Data data); /* FIXME [TRASH] */
void escreverSeguidores(int seguidores[], int qtd); /* FIXME [TRASH] */

/* Variáveis globais */
int n; /* quantidade de alunos a serem cadastrados */
Aluno *alunos;
int s; /* indice do aluno cuja popularidade é requisitada */

/* Programa Principal */
int main() {
	int i;

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

	/* Escreve o nome e a popularidade do aluno desejado */
	printf("%s ( %f )\n", alunos[s].nome, popularidade(ETAPAS, alunos[s]));
	
	/* Escreve o RA do aluno */
	printf("%d\n", alunos[s].ra);

	/* Escreve o genero do aluno */
	printf("%c\n", alunos[s].genero);

	/* Escreve a idade do aluno */
	printf("%d anos\n", idade(alunos[s].nascimento));

	printf("Seguidores: \n");

	for(i = 0; i < alunos[s].qtdSeguidores; i++)
		printf("\t%s\n", alunos[alunos[s].seguidores[i]].nome);
	

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
 * Calcula a popularidade de um aluno
 */
float popularidade(int t, Aluno aluno) {
	int i;
	float pop = 0.0;
	if(t == 0)
		return (float) 1/n;

	for(i = 0; i < aluno.qtdSeguidores; i++)
		pop += popularidade(t - 1, alunos[aluno.seguidores[i]])
					 / quantidadeDePessoasQueSegue(aluno.seguidores[i]);
	pop *= D;
	pop += (1 - D) / n;
	
	return pop;
}

/*
 * Calcula a quantidade de pessoas seguidas por um aluno
 */
int quantidadeDePessoasQueSegue(int seguidor) {
	int i, j, qtd = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < alunos[i].qtdSeguidores; j++)
			if(alunos[i].seguidores[j] == seguidor) {
				qtd++;
				break;
			}
	return qtd;
}

/*
 * Dada uma data de nascimento, calcula a idade da pessoa
 */
int idade(Data nascimento) {
	int idade = ANO - nascimento.ano;
	if(!jaPassou(nascimento))
		idade--;
	return idade;
}

/*
 * Verifica se a data já passou
 */
bool jaPassou(Data data) {
	return MES > data.mes || (MES == data.mes && DIA >= data.dia);
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
