#include <stdio.h>

enum bool {
	false,
	true
};

typedef enum bool bool;

bool ehBissexto(int ano) {
	if(ano % 4 == 0) {
		if(ano % 100 == 0) {
			if(ano % 400 == 0)
				return true;
		}
		return true;
	}

	return false;
}

int main() {
	int ano;

	printf("Digite um ano: ");
	scanf("%d", &ano);

	if(ehBissexto(ano))
		printf("É bissexto.\n");
	else
		printf("Não é bissexto.\n");

	return 0;
}
