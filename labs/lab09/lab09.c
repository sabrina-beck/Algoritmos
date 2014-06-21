#include <stdio.h>
#include <string.h>

#define CADASTRO 'c'
#define BUSCA 'b'
#define TAM_NOME_ALUNO 72
#define TAM_NOME_ARQUIVO 100
#define DIMENSAO 2
#define TAM_RA 7
#define TAM_ALFABETO 127
#define DIA 15
#define MES 5
#define ANO 2014

/*
 * Nome: Sabrina Beck Angelini
 * RA: 157240
 * Função do programa: Cadastrar e consultar alunos em arquivos binários
 * de maneira segura através da criptografia dos dados dos alunos.
 */

/* Enums e Estruturas */

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
	char nome[TAM_NOME_ALUNO];
	char genero;
	char ra[TAM_RA];
	Data nascimento;
	char generoQueProcura;
};

typedef struct Aluno Aluno;

/* Declaração de funções */

void cadastrar();
void cadastrarAlunos();
void lerAluno(Aluno *aluno);
void lerData(Data *data);
void gerarChave(Aluno aluno, int chave[DIMENSAO][DIMENSAO]);
void criptografar(char string[], int chave[DIMENSAO][DIMENSAO]);
void aplicarFiltro(int matriz[DIMENSAO][DIMENSAO], char c1, char c2, char resultado[]);
void buscar();
void buscarNoArquivo();
void descriptografar(char string[], int chave[DIMENSAO][DIMENSAO]);
int determinante(int matriz[DIMENSAO][DIMENSAO]);
int inversoMultiplicativo(int d);
void chaveInversa(int d_1, int chave[DIMENSAO][DIMENSAO], int matriz[DIMENSAO][DIMENSAO]);
int quantidadeDeAlunosCadastrados(char nomeArquivo[]);
void escreverAluno(Aluno aluno);
int calculaIdade(Data nascimento);
bool jaPassou(Data data);

/* Declaração de variáveis de escopo global */
char nomeArquivo[TAM_NOME_ARQUIVO];
int n;
int alunoProcurado;

/* Programa principal (main) */
int main() {
	char tipoEntrada;

	/* Lê a ação a ser tomada: Cadastro ou Busca? */
	scanf(" %c ", &tipoEntrada);

	if(tipoEntrada == CADASTRO)
		cadastrar();
	else if(tipoEntrada == BUSCA)
		buscar();

	return 0;
}

/* Implementações */

void cadastrar() {
	/* lê o nome do arquivo que será a base de dados */
	scanf("%[^\n]s", nomeArquivo);
	/* lê a quantidade de alunos a serem cadastrados */
	scanf(" %d ", &n);

	/* lê e cadastra alunos */
	cadastrarAlunos();
}

/*
 * lê os alunos da entrada padrão (stdin) e cadastra os alunos,
 * criptografando seus dados e salvando-os no arquivo especificado
 */
void cadastrarAlunos() {
	int i;	
	FILE* baseDeDados = fopen(nomeArquivo, "w+b");

	for(i = 0; i < n; i++) {
		Aluno aluno;
		int chave[DIMENSAO][DIMENSAO];
		lerAluno(&aluno);

		/* gera a chave de criptografia */
		gerarChave(aluno, chave);
		/* aplica a criptografia ao nome e RA do aluno */
		criptografar(aluno.nome, chave);
		criptografar(aluno.ra, chave);

		/* Exibe na tela o nome e o ra do aluno criptografados */
		printf("%s\n", aluno.nome);
		printf("%s\n", aluno.ra);

		/* Cadastra o aluno gravando seus dados no arquivo especificado */
		fwrite(&aluno, sizeof(Aluno), 1, baseDeDados);
	}

	fclose(baseDeDados);
}

/*
 * lê os dados de um aluno da entrada padrão (stdin)
 */
void lerAluno(Aluno *aluno) {
	scanf("%[^\n]s", aluno->nome);
	scanf("%s ", aluno->ra);
	scanf(" %c ", &aluno->genero);
	lerData(&aluno->nascimento);
	scanf(" %c ", &aluno->generoQueProcura);
}

/*
 * lê uma data no formato dd/mm/aaaa da entrada padrão (stdin)
 */
void lerData(Data *data) {
	scanf("%hu/%hu/%hu ", &data->dia, &data->mes, &data->ano);
}

/*
 * Gera a chave de criptografia para um determinado aluno
 * dada a data de nascimento do aluno d1d2/m1m2/a1a2a3a4
 * a chave será:
 * chave[0][0] = a1a2
 * chave[0][1] = m1m2
 * chave[1][0] = d1d2
 * chave[1][1] = a3a4
 */
void gerarChave(Aluno aluno, int chave[DIMENSAO][DIMENSAO]) {
	chave[0][0] = aluno.nascimento.ano / 100;
	chave[0][1] = aluno.nascimento.mes;
	chave[1][0] = aluno.nascimento.dia;
	chave[1][1] = aluno.nascimento.ano % 100;
}

/*
 * Dada uma chave, aplica a cifra de Hill para criptografar uma string
 */
void criptografar(char string[], int chave[DIMENSAO][DIMENSAO]) {
	int i;
	char resultado[2];

	/* Percorre a string aos pares de caracteres */
	for(i = 0; string[i] && string[i + 1]; i += 2) {
		/* criptografa os caracteres atuais */
		aplicarFiltro(chave, string[i], string[i + 1], resultado);
		string[i] = resultado[0];
		string[i + 1] = resultado[1];
	}

	/*
	 * Caso a string tenha tamanho impar, criptografa seu ultimo caracter
	 * considerando como seu par o ' '
	 */
	if(string[i] && !string[i + 1]){
		aplicarFiltro(chave, string[i], ' ', resultado);
		string[i] = resultado[0];
		string[i + 1] = resultado[1];
		string[i + 2] = '\0';
	}
}

/*
 * Dada uma chave, aplica a cifra de Hill para dois caracteres
 */
void aplicarFiltro(int matriz[DIMENSAO][DIMENSAO], char c1, char c2, char resultado[]) {
	resultado[0] = ((matriz[0][0] * (int) c1) + (matriz[0][1] * (int) c2)) % TAM_ALFABETO;
	resultado[1] = ((matriz[1][0] * (int) c1) + (matriz[1][1] * (int) c2)) % TAM_ALFABETO;
}

void buscar() {
	/* lê nome do arquivo com a base de dados */
	scanf("%[^\n]s", nomeArquivo);
	/* lê posição do aluno procurado na base de dados */
	scanf("%d ", &alunoProcurado);

	buscarNoArquivo();
}

/*
 * Busca o aluno procurado na base de dados
 */
void buscarNoArquivo() {
	FILE* baseDeDados = fopen(nomeArquivo, "rb");
	Aluno aluno;
	int chave[DIMENSAO][DIMENSAO];

	/* Muda posição do ponteiro de leitura do arquivo para a posição do aluno procurado */
	fseek(baseDeDados, (alunoProcurado - 1) * sizeof(Aluno), SEEK_SET);
	/* lê o aluno procurado da base de dados */
	fread(&aluno, sizeof(Aluno), 1, baseDeDados);

	/* Gera a chave de criptografia do aluno procurado */
	gerarChave(aluno, chave);

	/* Decifra o nome e o ra do aluno procurado */
	descriptografar(aluno.nome, chave);
	descriptografar(aluno.ra, chave);

	/* Calcula a quantidade de alunos cadastrados na base de dados */
	fseek(baseDeDados, 0, SEEK_END);
	n = ftell(baseDeDados) / sizeof(Aluno);

	/*
	 * Exibe a posição do aluno procurado na base de dados / a 
	 * quantidade de alunos cadastrados
	 */
	printf("%d/%d\n", alunoProcurado, n);
	/* Exibe os dados do aluno procurado */	
	escreverAluno(aluno);

	fclose(baseDeDados);
}

/*
 * Dada uma chave, descriptografa uma string, segundo a cifra de Hill
 */
void descriptografar(char string[], int chave[DIMENSAO][DIMENSAO]) {
	int i;
	int inversaModulo[DIMENSAO][DIMENSAO];
	int d_1 = inversoMultiplicativo(determinante(chave));

	/* Calcula a chave inversa da criptografia de Hill */
	chaveInversa(d_1, chave, inversaModulo);
	
	/* Descriptografa a string par a par de caracteres */
	for(i = 0; string[i] && string[i + 1]; i += 2) {
		char par[2];

		/* Aplica a criptografia ao par atual de caracteres */
		aplicarFiltro(inversaModulo, string[i], string[i + 1], par);
		string[i] = par[0];
		string[i + 1] = par[1];
	}
}

/*
 * Calcula o determinante de uma matriz 2x2
 */
int determinante(int matriz[DIMENSAO][DIMENSAO]) {
	return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
}

/*
 * Dado o determinante de uma matriz, calcula o número inverso multiplicativo do mesmo
 */
int inversoMultiplicativo(int d) {
	int x;
	for(x = 1; (d * x) % TAM_ALFABETO != 1; x++);
	return x;
}

/*
 * Dada uma chave de criptografia, calcula a chave para decifrar o código
 */
void chaveInversa(int d_1, int chave[DIMENSAO][DIMENSAO], int matriz[DIMENSAO][DIMENSAO]) {
	int i, j;

	/* Calcula a matriz inicial */
	matriz[0][0] = chave[1][1];
	matriz[0][1] = -chave[0][1];
	matriz[1][0] = -chave[1][0];
	matriz[1][1] = chave[0][0];

	/* Aplica o numero inverso multiplicativo a chave inversa */
	for(i = 0; i < DIMENSAO; i++)
		for(j = 0; j < DIMENSAO; j++)
			matriz[i][j] = ((d_1 * matriz[i][j]) % TAM_ALFABETO) + TAM_ALFABETO;
}

/*
 * Escreve os dados de um aluno na tela
 */
void escreverAluno(Aluno aluno) {
		printf("%s\n", aluno.nome);
		printf("%s\n", aluno.ra);
		printf("%c\n", aluno.genero);
		printf("%d anos\n", calculaIdade(aluno.nascimento));
}

/*
 * Dada uma data de nascimento, calcula a idade da pessoa
 */
int calculaIdade(Data nascimento) {
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
