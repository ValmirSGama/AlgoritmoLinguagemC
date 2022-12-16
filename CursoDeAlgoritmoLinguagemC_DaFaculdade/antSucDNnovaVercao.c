#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	printf("Digite o número: ");
	scanf ("%d", &num);
	printf("\n O antecessor é: %d", num -1);
	printf("\n O sucessor é: %d\n", num +1);
	system("pause");
	return (0);
	
}
