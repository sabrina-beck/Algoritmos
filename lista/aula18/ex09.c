#include <stdio.h>

double pot (double base, int exp);

int main() {
	double base;
	int exp;

	printf("Digite dois valores: ");
	scanf("%lf %d", &base, &exp);

	printf("%.2f^%d = %.2f\n", base, exp, pot(base, exp));

	return 0;
}

double pot (double base, int exp) {
	if(exp == 0.0)
		return 1.0;
	if(exp % 2 == 0)
		return pot(base, exp/2) * pot(base, exp/2);
	return base * pot(base, exp/2) * pot(base, exp/2);
}
