#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int cargo;
	float salario, aumento,salario_final;
	printf ("Digite o número do cargo do funcionário [1|2|3|4]: \n");
	scanf ("%d", &cargo);
	printf("Digite o valor do salário do funcionário: \n");
	scanf ("%f", &salario);
	switch (cargo){
		case 1:
			aumento = salario * 0.4;
			salario_final = salario + aumento;
			printf ("O Servente teve aumento de R$ %.2f e agora recebe R$ %.2f \n", aumento, salario_final);
			break;
		case 2:
			aumento = salario * 0.35;	
			salario_final = salario + aumento;
			printf("O Pedreiro teve aumento de R$ %.2f e agora recebe R$ %.2f \n", aumento, salario_final);
			break;
		case 3:
			aumento = salario * 0.20;
			salario_final = salario + aumento;
			printf("O Mestre de Obras teve aumento de R$ %.2f e agora recebe R$ %.2f \n", aumento, salario_final);
			break;
		case 4:
			aumento = salario * 0.10;
			salario_final = salario + aumento;
			printf("O Técnico de Segurança teve aumento de R$ %.2f e agora recebe R$ %.2f \n", aumento, salario_final);
			break;
		default:
			printf("Opção inválida.");
			break;
	}
	system("pause");
	return (0);
}
