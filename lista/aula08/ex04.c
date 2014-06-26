#include <stdio.h>

int main() {
	int votos[115], i, papa = 0;

	for(i = 0; i < 115; i++)
		votos[i] = 0;

	for(i = 0; i < 114; i++) {
		int voto;		
		printf("Qual é o cardeal indicado? ");
		scanf("%d", &voto);
		votos[voto]++;
	}

	for(i = 0; i < 115 && !papa; i++)
		if(votos[i] >= 77)
			papa = i;

	if(papa)
		printf("Habemos Papam: %d\n", papa);

	return 0;
}
