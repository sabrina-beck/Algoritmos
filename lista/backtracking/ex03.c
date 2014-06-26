#include <stdio.h>

#define MAX 100
#define MOVES 8

typedef enum bool bool;

int main() {

	return 0;
}

int labirinto(int n, int mapa[MAX][MAX], int xInicial, int yInicial, int xFinal, int yFinal, int moveX[] int moveY[]) {
	if(xInicial == xFinal && yInicial == xFinal)
		return mapa[xInicial][yInicial];
	else {
		int i;
		for(i = 0; i < MOVES; i++) {
			int nextX = xInicial + moveX[i];
			int nextY = yInicial + moveY[i];

			if((nextX >= 0 && nextX < n) && (nextY >= 0 && nextY < n) &&
				mapa[nextX][nextY] == 0) {
				mapa[nextX][nextY] = mapa[xInicial][yInicial] + 1;

				passos = labirinto(n, mapa, nextX, nextY, xFinal, yFinal, moveX, moveY);

				if(passos > 0) return passos;
			}
		}
	}

	return 0;
}
