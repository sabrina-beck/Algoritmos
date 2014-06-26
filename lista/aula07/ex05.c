#include <stdio.h>
#include <math.h>

enum bool {
	false,
	true
};

typedef enum bool bool;

int main() {
	int n, i;
	bool primo = true;

	printf("Digite um valor: ");
	scanf("%d", &n);

	for(i = 2; i <= sqrt(n); i++)
		if(n % i == 0) {
			primo = false;
			break;
		}

	if(primo)
		printf("É primo.\n");
	else
		printf("Não é primo.\n");

	return 0;
}
