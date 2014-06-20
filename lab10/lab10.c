#include <stdio.h>
#include <stdlib.h>

#define CASA_VAZIA '.'
#define PAREDE 'X'
#define TORRE 'T'
#define QTD_DIRECOES 4


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
int** alocarI(int n);
void lerMatriz(char **matriz, int n);
void configuracoesPossiveis(int x, int y, char **tabuleiro, int n);
bool validaTorre(char **tabuleiro, int n, int x, int y);
int quantidadeDeTorres(char **tabuleiro, int n);
void zerarMatriz(int **mat, int n);

int direcoes[QTD_DIRECOES][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int maior = 0;
int **aux; /* matriz que armazena as posições do tabuleiro que já foram visitadas */

int main() {
	int n, i, j; /* tamanho do tabuleiro */
	char **tabuleiro;

	/* Lê o tamanho do tabuleiro */
	scanf("%d ", &n);

	/* Aloca uma matriz para o tabuleiro */
	tabuleiro = alocar(n);
	aux = alocarI(n);

	/* Lê o tabuleiro */
	lerMatriz(tabuleiro, n);

	zerarMatriz(aux, n);

	/*
	 * Calcula o numero maximo de torres possíveis de se colocar
	 * no tabuleiro sem que uma possa atacar a outra
	 */
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			configuracoesPossiveis(i, j, tabuleiro, n);
			zerarMatriz(aux, n);
		}

	/*
	 * Escreve o numero maximo de torres possíveis de se colocar
	 * no tabuleiro sem que uma possa atacar a outra
	 */
	printf("%d\n", maior);

	return 0;
}

void zerarMatriz(int **mat, int n) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			mat[i][j] = 0;
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
 * Aloca uma matriz quadrada de int de dimensão nxn
 */
int** alocarI(int n) {
	int i;
	int **matriz = (int**) malloc(n * sizeof(char));
	for(i = 0; i < n; i++)
		matriz[i] = malloc(n * sizeof(char));
	return matriz;
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
 * Marca que o algoritimo já passou por determinada posição do tabuleiro
 */
void passouPor(int x, int y) {
	aux[x][y]++;
}

/*
 * Verifica se o algoritimo já passou por determinada posição do tabuleiro
 */
bool jaPassouPor(int x, int y, int n) {
	return aux[x][y] > 0;
}

/*
 * Calcula o numero maximo de torres possíveis de se colocar
 * no tabuleiro sem que uma possa atacar a outra
 */
void configuracoesPossiveis(int x, int y, char **tabuleiro, int n) {
	int i;
	/* Caso de parada é quando ultrapassa os limites da matriz */
	if(x >= n || y >= n || x < 0 || y < 0 || jaPassouPor(x, y, n)) {
		int qtdTorres = quantidadeDeTorres(tabuleiro, n);
		if(qtdTorres > maior)
			maior = qtdTorres;

		return;
	}

	passouPor(x, y);

	/*
	 * Se a casa atual é uma casa vazia e uma posição válida para a torre,
	 * uma torre é colocada nessa posição
	 */
	if(tabuleiro[x][y] == CASA_VAZIA && validaTorre(tabuleiro, n, x, y)) {
		tabuleiro[x][y] = TORRE;
	}

	/*
	 * Calcula todas as possíveis configurações de torres no tabuleiro,
	 * armazenando a maior quantidade de torres
	 */
	for(i = 0; i < QTD_DIRECOES; i++) {
		configuracoesPossiveis(x + direcoes[i][0], 
					y + direcoes[i][1], tabuleiro, n);

	}

	/*
	 * Caso uma torre tenha sido colocada no tabuleiro,
	 * a mesma é retirada para testar outras configurações
	 */
	if(tabuleiro[x][y] == TORRE)
		tabuleiro[x][y] = CASA_VAZIA;

}

/*
 * Verifica se as torres posicionadas não podem se atacar
 */
bool validaTorre(char **tabuleiro, int n, int x, int y) {
	int i;

	/* Verifica a linha da torre */
	for(i = x - 1; i >= 0 && tabuleiro[i][y] != PAREDE; i--)
		if(tabuleiro[i][y] == TORRE)
			return false;

	for(i = x + 1; i < n && tabuleiro[i][y] != PAREDE; i++)
		if(tabuleiro[i][y] == TORRE)
			return false;

	/* Verifica a coluna da torre */
	for(i = y - 1; i >= 0 && tabuleiro[x][i] != PAREDE; i--)
		if(tabuleiro[x][i] == TORRE)
			return false;

	for(i = y + 1; i < n && tabuleiro[x][i] != PAREDE; i++)
		if(tabuleiro[x][i] == TORRE)
			return false;

	return true;
}

/*
 * Calcula a quantidade de torres no tabuleiro
 */
int quantidadeDeTorres(char **tabuleiro, int n) {
	int i, j, cont = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(tabuleiro[i][j] == TORRE)
				cont++;
	return cont;
}
