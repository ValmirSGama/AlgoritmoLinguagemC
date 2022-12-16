#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int i, j, valor;
	for (i = 1; i <= 10; i++){
		printf("Tabuada do %d \n", i);
		for (j = 1; j <= 10; j++){
			valor = i * j;
			printf("%d x %d = %d\n", i, j, valor);
		}
	}
	system("pause");
	return (0);
}
