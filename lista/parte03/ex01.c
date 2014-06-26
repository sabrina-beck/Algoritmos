#include <stdio.h>

int main() {
	int n, i, valor;
	int inter1 = 0, inter2 = 0, inter3 = 0, inter4 = 0, inter5 = 0, inter6 = 0;

	printf("Quantos valores serão lidos? ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		printf("Digite um valor: ");
		scanf("%d", &valor);

		if(valor <= 0)
			inter1++;
		else if(valor <= 25)
			inter2++;
		else if(valor <= 50)
			inter3++;
		else if(valor <= 75)
			inter4++;
		else if(valor <= 100)
			inter5++;
		else
			inter6++;
	}

	printf("%d valores pertencentes a (-infinito, 0].\n", inter1);
	printf("%d valores pertencentes a (0, 25].\n", inter2);
	printf("%d valores pertencentes a (25, 50].\n", inter3);
	printf("%d valores pertencentes a (50, 75].\n", inter4);
	printf("%d valores pertencentes a (75, 100].\n", inter5);
	printf("%d valores pertencentes a (100, infinito].\n", inter6);

	return 0;
}
