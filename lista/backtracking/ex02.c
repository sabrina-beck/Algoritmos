#include <stdio.h>

#define MAX 100
#define MOVES 8

enum bool {
	false, true
}

typedef enum bool bool;

bool passeio(int n, int x, int y, int pos, int tabuleiro[MAX][MAX], int xMove[], int yMove);

int main() {
	int n, x, y;



	return 0;
}

bool passeio(int n, int x, int y, int pos, int tabuleiro[MAX][MAX], int xMove[], int yMove) {
	if(pos == n*n)
		return true;
	else {
		int i;
		for(i = 0; i < MOVES; i++) {
			int nextX = x + xMove[i];
			int nextY = y + yMove[i];

			if((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < n) 
				&& tabuleiro[x][y] == 0) {
				tabuleiro[nextX][nextY] = pos + 1;
				if(passeio(n, nextX, nextY, pos + 1, tabuleiro, xMove, yMove)
					return true;
				tabuleiro[x][y] = 0;
			}
		}
	}

	return false;
}
