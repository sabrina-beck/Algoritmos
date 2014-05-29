#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INICIO_DE_COMENTARIO '#'
#define TAMANHO_CABECALHO 3
#define TAMANHO_LINHA 71
#define ESPACO ' '
#define NOVA_LINHA '\n'
#define TAMANHO_VIZINHANCA 3

/********************** Declarações ********************/
enum bool {
	false,
	true
};

typedef enum bool bool;

int toInt(char c);

void ordenar(int[], int);
float mediana(int[], int);

int **alocar(int, int);
void desalocar(int**, int);

void lerLinha(char[], int);
void lerMatriz(int**, int, int);
void imprimirMatriz(int**, int, int);

void lerImagem ();
void escreverImagem();

int vizinho(int, int);
void obterVizinhanca(int[], int, int);
bool existeAPosicao(int, int);
void filtrarImagem();

/********************** Variaveis ********************/
char p2[TAMANHO_CABECALHO]; /* contem o cabecalho "P2" */
int largura, altura, intensidadeMax;
int **imagem, **imagemComFiltro;

int valorMaximo, valorMinimo, erroMedioAbsoluto = 0;

/********************** Programa principal ********************/

int main() {
	lerImagem();

	filtrarImagem();

	escreverImagem();

	desalocar(imagem, altura);
	desalocar(imagemComFiltro, altura);

	return 0;
}

/********************** Implementação das funções ********************/

/*
 * Converte um caracter em um inteiro:
 * 	'0' = 48, '1' = 49,
 * 	'2' = 50, '3' = 51,
 * 	'4' = 52, '5' = 53,
 * 	'6' = 54, '7' = 55,
 * 	'8' = 56, '9' = 57,
 * Retorna -1 se o caracter não representa um inteiro.
 */
int toInt(char c) {
	if(c >= 48 && c <= 57)
		return (int) c - 48;
	return -1;
}

/*
 * Aloca memoria para uma matriz de n linhas e m colunas;
 */
int **alocar(int linhas, int colunas){
	int i;
	int **matriz = (int**) malloc(linhas * sizeof(int*));
	for(i = 0; i < linhas; i++)
		matriz[i] = (int*) malloc(colunas * sizeof(int));
	return matriz;
}

/*
 * Libera a memória alocada para uma matriz de n linhas;
 */
void desalocar(int **matriz, int linhas) {
	int linhaAtual;
	for(linhaAtual = 0; linhaAtual < linhas; linhaAtual++)
		free(matriz[linhaAtual]);
	free(matriz);
}

/*
 * Le as linhas de entrada e monta uma matriz com n linhas e m colunas
 * preenchendo-a com os dados presentes nas linhas de entrada separados por espaço
 */
void lerMatriz(int **matriz, int linhas, int colunas) {
	int linhaAtual = 0, colunaAtual = 0, i;
	char linhaLida[TAMANHO_LINHA];
	/* 
	 * Nao eh possivel utilizar o scanf para ler os dados da matriz no formato int, 
	 * uma vez que podem haver n espacos em branco entre cada valor 
	 */
	lerLinha(linhaLida, TAMANHO_LINHA);
	setbuf(stdin, 0);
	/*
	 * Enquanto não preencher todas as linhas da matriz, continua lendo
	 */
	for(linhaAtual = 0; linhaAtual < linhas;) {
		/* Percorre a linha lida*/
		for(i = 0; linhaLida[i]; i++) {
			bool ehUmValor = false;
			matriz[linhaAtual][colunaAtual] = 0;
			/*
			 * Ignora os espaços em branco e o caracter de nova linha, 
			 * ateh encontrar um numero que sera armazenado na matriz
			 */
			while(linhaLida[i] != ESPACO && linhaLida[i] != NOVA_LINHA && linhaLida[i] && colunaAtual < colunas) {
				matriz[linhaAtual][colunaAtual] *= 10;
				matriz[linhaAtual][colunaAtual] += toInt(linhaLida[i]);
				i++;
				ehUmValor = true;
			}

			/*
			 * Sempre que encontrar um valor que eh armazenado na matriz avançamos 
			 * uma posicao na matriz que receberá o proximo valor lido
			 */
			if(ehUmValor) {
				colunaAtual++;
				if(colunaAtual >= colunas) {
					colunaAtual = 0;
					linhaAtual++;
					if(linhaAtual >= linhas)
						break;
				}
			}
		}
		if(linhaAtual >= linhas)
			break;
		lerLinha(linhaLida, TAMANHO_LINHA);
		setbuf(stdin, 0);
	}
}

/*
 * Exibe na tela os dados de uma matriz com n linhas e m colunas
 */
void imprimirMatriz(int **matriz, int linhas, int colunas) {
	int linhaAtual, colunaAtual;
	for(linhaAtual = 0; linhaAtual < linhas; linhaAtual++) {
		for(colunaAtual = 0; colunaAtual < colunas; colunaAtual++)
			printf("%d ", matriz[linhaAtual][colunaAtual]);
		printf("\n");
	}
}

/*
 * Le os dados da imagem:
 *   - Armazena o tipo da imagem na varivel p2
 *   - Ignora os comentários
 *   - Armazena a largura e a altura nas variaveis de mesmo nome
 *   - Armazena a intensidade máxima na variável intensidadeMax
 *   - Armazena a matriz na variavel imagem
 * e inicializa as variveis de valor maximo e minimo;
 */
void lerImagem () {
	char comentario[TAMANHO_LINHA];

	/* Le o tipo da imagem "P2" */
	lerLinha(p2, TAMANHO_CABECALHO);
	setbuf(stdin, 0);
	
	/* Le os comentarios */
	lerLinha(comentario, TAMANHO_LINHA);
	setbuf(stdin, 0);
	while(comentario[0] == INICIO_DE_COMENTARIO) {
		lerLinha(comentario, TAMANHO_LINHA);
		setbuf(stdin, 0);
	}

	/* Le a largura e a altura da imagem */
	sscanf(comentario, "%d %d", &largura, &altura);

	while(largura == 0 && altura == 0) {
		lerLinha(comentario, TAMANHO_LINHA);
		sscanf(comentario, "%d %d", &largura, &altura);
	}

	/* Le o valor maximo de intensidade que pode ser representado na matriz */
	scanf("%d", &intensidadeMax);
	setbuf(stdin, 0);

	/* Le a matriz */
	imagem = alocar(altura, largura);
	lerMatriz(imagem, altura, largura);

	/* Inicia as variaveis com valores de saida */
	valorMaximo = imagem[0][0];
	valorMinimo = imagem[0][0];

}

/*
 * Realiza o filtro da mediana na imagem armazenando a matriz
 * resultante na variavel imagemComFiltro e calcula os valores maximo
 * e minimo e o erro medio absoluto
 */
void filtrarImagem() {
	int i, j;
	imagemComFiltro = alocar(altura, largura);
	for(i = 0; i < altura; i++)
		for(j = 0; j < largura; j++) {
			int vizinhanca[TAMANHO_VIZINHANCA*TAMANHO_VIZINHANCA];
			int qtdVizinhos = TAMANHO_VIZINHANCA*TAMANHO_VIZINHANCA;

			/* Aplicação do filtro */
			obterVizinhanca(vizinhanca, i, j);
			ordenar(vizinhanca, qtdVizinhos);
			imagemComFiltro[i][j] = (int) mediana(vizinhanca, qtdVizinhos);

			/* Guardando valores maximo e minimo */
			if(imagem[i][j] > valorMaximo)
				valorMaximo = imagem[i][j];
			if(imagem[i][j] < valorMinimo)
				valorMinimo = imagem[i][j];
			erroMedioAbsoluto += fabs(imagem[i][j] - imagemComFiltro[i][j]);
		}
}

/*
 * Ordena um vetor pelo metodo de insertion sort
 */
void ordenar(int numeros[], int tam) {
	int i, j, eleito;

	for (i = 1; i < tam; i++){
		eleito = numeros[i];
		j = i - 1;
		while ((j>=0) && (eleito < numeros[j])) {
			numeros[j+1] = numeros[j];
			j--;
		}
		numeros[j+1] = eleito;
	}

}

/*
 * Armazena em um vetor os valores vizinhos a posicao (i,j)
 * inclusive ele da matriz imagem
 */
void obterVizinhanca(int vizinhanca[], int i, int j) {
	vizinhanca[0] = vizinho(i-1, j-1);
	vizinhanca[1] = vizinho(i-1, j);
	vizinhanca[2] = vizinho(i-1, j+1);
	vizinhanca[3] = vizinho(i, j);
	vizinhanca[4] = vizinho(i, j-1);
	vizinhanca[5] = vizinho(i, j+1);
	vizinhanca[6] = vizinho(i+1, j-1);
	vizinhanca[7] = vizinho(i+1, j);
	vizinhanca[8] = vizinho(i+1, j+1);
}

/*
 * Retorna o valor da posicao (linhaImagem, colunaImagem) da matriz imagem
 * se a posicao nao existir retorna 0
 */
int vizinho(int linhaImagem, int colunaImagem) {
	if(existeAPosicao(linhaImagem, colunaImagem))
		return imagem[linhaImagem][colunaImagem];
	else
		return 0;

}

/*
 * Verifica se a posicao (linha, coluna) existe na matriz imagem
 */
bool existeAPosicao(int linha, int coluna) {
	return linha >= 0 && linha < altura && coluna >= 0 && coluna < largura;
}

/*
 * Calcula a mediana de um vetor
 */
float mediana(int numeros[], int tam) {
	if(tam % 2)
		return (float) numeros[(tam) / 2];
	return (float)(numeros[(tam / 2) - 1] + numeros[tam / 2]) / 2;
}

/*
 * Escreve a imagem com o filtro da mediana aplicado, incluindo
 * valores maximo e minimo e o erro medio absoluto
 */
void escreverImagem() {
	printf("%s\n", p2);
	printf("# MAX = %d\n", valorMaximo);
	printf("# MIN = %d\n", valorMinimo);
	printf("# AE = %d\n", erroMedioAbsoluto);
	printf("%d %d\n", largura, altura);
	printf("%d\n", intensidadeMax);
	imprimirMatriz(imagemComFiltro, altura, largura);
}

/*
 * Le uma linha, ignorando linhas que contenham apenas o caracter '\n'
 */
void lerLinha(char linha[], int tamanho) {
	fgets(linha, tamanho, stdin);
	while(linha[0] == '\n' && linha[1] == '\0')
		fgets(linha, tamanho, stdin);
}
