#include <stdio.h>
#include <math.h>
#define pi 3.141593
int main()
{
	float r; // r (raio da circunferência)
	printf("Digite o valor do raio: ");
	scanf ("%f", &r);
	printf("\n valor da area: %f", pi * pow(r,2));
	printf("\n valor do perimetro: %f", 2 * pi * r);
	return (0);
}
