#include <stdio.h>

int main() {
	int dividendo, divisor, quociente;

	printf("Digite o dividendo e o divisor: ");
	scanf("%d %d", &dividendo, &divisor);

	quociente = 0;

	while(dividendo >= divisor) {
		dividendo -= divisor;
		quociente++;
	}

	printf("%d\n", quociente);

	return 0;
}
