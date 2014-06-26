#include <stdio.h>

int main() {
	float celsius, fahrenheit, kelvin;

	printf("Digite uma temperatura em graus Celsius: ");
	scanf("%f", &celsius);

	fahrenheit = (9.0/5.0) * celsius + 32;
	kelvin = celsius + 273;

	printf("Fahrenheit: %.2fºF\n", fahrenheit);
	printf("Kelvin: %.2fK\n", kelvin);

	return 0;
}
