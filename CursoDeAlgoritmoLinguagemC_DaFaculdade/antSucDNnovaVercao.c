#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	printf("Digite o n�mero: ");
	scanf ("%d", &num);
	printf("\n O antecessor �: %d", num -1);
	printf("\n O sucessor �: %d\n", num +1);
	system("pause");
	return (0);
	
}
