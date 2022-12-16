#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int idade;
	printf("Qual a sua idade: ");
	scanf ("%d", &idade);
	if (idade < 16){
		printf("%d Anos, Não eleitor \n", idade);
	}
	else
	{
		if ((idade < 18) || (idade > 65)){
			printf("%d Anos, eleitor facultativo \n", idade);
		}
		else
		{
			printf("%d Anos, eleitor obrigatório \n", idade);
		}
	}
	system("pause");
	return (0);
}
