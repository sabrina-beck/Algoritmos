#include <stdio.h>

enum bool {
	false, true
};

typedef enum bool bool;

int main() {
	int n;
	bool impar = false, anteriorImpar;

	printf("Digite um número: ");
	scanf("%d", &n);

	if(n % 2 != 0)
		impar = true;
	n /= 10;

	while(n > 0){
		anteriorImpar = impar;
		impar = n % 2 != 0;

		if(impar == anteriorImpar) {
			printf("Não é alternante.\n");
			return 0;
		}

		n /= 10;
	}

	printf("É alternante.\n");

	return 0;
}
