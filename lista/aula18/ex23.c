#include <stdio.h>

double potencia(double x, int k);
double pot(double x, int k);

int main() {
	double x;
	int k;

	printf("x: ");
	scanf("%lf", &x);
	printf("k: ");
	scanf("%d", &k);

	printf("%.2f ^ %d = %.2f\n", x, k, potencia(x, k));
	printf("%.2f ^ %d = %.2f\n", x, k, pot(x, k));

	return 0;
}

double potencia(double x, int k) {
	if(k == 0)
		return 1;
	if(k == 1)
		return x;
	if(k % 2 == 0)
		return potencia(x, k/2) * potencia(x, k/2);
	return x * potencia(x, k/2) * potencia(x, k/2);
}

double pot(double x, int k) {
	if(k == 0)
		return 1;
	return x * pot(x, k - 1);
}
