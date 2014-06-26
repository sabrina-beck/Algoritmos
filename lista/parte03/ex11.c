#include <stdio.h>

int main() {
	int pa, pb, ta, tb, anos;

	printf("Qual o numero de habitantes da população A? ");
	scanf("%d", &pa);
	printf("E sua taxa anual de crescimento? ");
	scanf("%d", &ta);

	printf("Qual o numero de habitantes da população B? ");
	scanf("%d", &pb);
	printf("E sua taxa anual de crescimento? ");
	scanf("%d", &tb);

	for(anos = 0; pa < pb; anos++) {
		pa += ta;
		pb += tb;
	}

	printf("%d anos para a população A ultrapassar a população B. \n", anos);

	return 0;
}
