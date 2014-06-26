#include <stdio.h>

int main() {
	int n, i;
	float harmonico = 0.0;

	printf("Qual é o numero harmonico desejado? ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
		harmonico += (float) 1 / i;

	printf("%.5f\n", harmonico);

	return 0;
}
