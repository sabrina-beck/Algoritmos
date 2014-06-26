#include <stdio.h>

#define SIM "SIM\n"
#define NAO "NAO\n"

int main() {
	int m, n, m1, n1;

	printf("Digite dois valores: ");
	scanf("%d %d", &m, &n);

	m1 = m;
	n1 = n;
	while(m1 > 0) {
		if((m1 % 10) == (n1 % 10)) {
			n1 /= 10;
		} else
			n1 = n;

		if(n1 == 0) {
			printf(SIM);
			return 0;
		}

		m1 /= 10;
	}

	printf(NAO);

	return 0;
}
