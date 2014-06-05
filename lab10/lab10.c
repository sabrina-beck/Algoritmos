#include <stdio.h>
#include <stdlib.h>

#define CASA_VAZIA '.'
#define PAREDE 'X'

/*
 * Nome: Sabrina Beck Angelini
 * RA: 157240
 * Descrição: Programa que lê um tabuleiro com possíveis obstáculos e
 * calcula quantidade máxima de torres que podem ser posicionadas em
 * suas posições livres sem que elas possam se atacar.
 */

/********************** ENUMS e STRUCTS **********************/
enum bool {
	false,
	true
};

typedef enum bool bool;

/********************** DECLARAÇÔES DE FUNÇÔES **********************/
char** alocar(int n);
void desalocar(char** matriz, int n);
void lerMatriz(char **matriz, int n);
void escreverMatriz(char **matriz, int n); /* FIXME TIRAR ISSO */
int calculaNumeroMaximoDeTorres(char **tabuleiro, int n);
bool validaTorres(char **tabuleiro, int n);

int main() {
	int n; /* tamanho do tabuleiro */
	char **tabuleiro;
	int numeroMaximoDeTorres;

	/* Lê o tamanho do tabuleiro */
	scanf("%d ", &n);

	/* Aloca uma matriz para o tabuleiro */
	tabuleiro = alocar(n);

	/* Lê o tabuleiro */
	lerMatriz(tabuleiro, n);

	/* FIXME: escreve o tabuleiro --> TIRAR ISSO */
	/*escreverMatriz(tabuleiro, n);*/

	/*
	 * Calcula o numero maximo de torres possíveis de se colocar
	 * no tabuleiro sem que uma possa atacar a outra
	 */
	numeroMaximoDeTorres = calculaNumeroMaximoDeTorres(tabuleiro, n);

	/*
	 * Escreve o numero maximo de torres possíveis de se colocar
	 * no tabuleiro sem que uma possa atacar a outra
	 */
	printf("%d", numeroMaximoDeTorres);

	/* Desaloca a matriz do tabuleiro */
	/* FIXME desalocar nao esta funcionando */
	/*desalocar(tabuleiro, n);*/

	return 0;
}

/*
 * Aloca uma matriz quadrada de char de dimensão nxn
 */
char** alocar(int n) {
	int i;
	char **matriz = (char**) malloc(n * sizeof(char));
	for(i = 0; i < n; i++)
		matriz[i] = malloc(n * sizeof(char));
	return matriz;
}

/*
 * Desaloca uma matriz quadrada de char de dimensao nxn
 */
/* FIXME desalocar nao esta funcionando */
void desalocar(char** matriz, int n) {
	int i;
	for (i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}

/*
 * Lê uma matriz quadrada de chars de dimensao nxn
 */
void lerMatriz(char **matriz, int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			scanf("%c", &matriz[i][j]);
		scanf("\n");
	}
}

/*
 * FIXME: Escreve uma matriz quadrada de dimensao nxn --> TIRAR ISSO
 */
void escreverMatriz(char **matriz, int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%c", matriz[i][j]);
		printf("\n");
	}
}

/*
 * Calcula o numero maximo de torres possíveis de se colocar
 * no tabuleiro sem que uma possa atacar a outra
 */
/* TODO */
int calculaNumeroMaximoDeTorres(char **tabuleiro, int n) {
	return 0;
}

/*
 * Verifica se as torres posicionadas não podem se atacar
 */
/* TODO */
bool validaTorres(char **tabuleiro, int n) {
	return false;	
}
