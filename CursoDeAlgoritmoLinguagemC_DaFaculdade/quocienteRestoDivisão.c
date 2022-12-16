 #include <stdio.h>
 #include <locale.h>
 
 int main()
 {
 	setlocale(LC_ALL,"");
 	int dividendo, divisor, quociente, resto;
 	printf("Digite o 1° número: ");
 	scanf ("%d", &dividendo);
 	printf("Digite o 2° número: ");
 	scanf ("%d", &divisor);
 	
 	quociente = dividendo / divisor;
 	resto = dividendo % divisor;
 	
 	printf("O quociente é: %d \n", quociente);
 	printf("O resto é: %d \n", resto);
 	
 	system("pause");
 	return (0);
 }
 
