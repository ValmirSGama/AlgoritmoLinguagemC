 #include <stdio.h>
 #include <locale.h>
 
 int main()
 {
 	setlocale(LC_ALL,"");
 	int dividendo, divisor, quociente, resto;
 	printf("Digite o 1� n�mero: ");
 	scanf ("%d", &dividendo);
 	printf("Digite o 2� n�mero: ");
 	scanf ("%d", &divisor);
 	
 	quociente = dividendo / divisor;
 	resto = dividendo % divisor;
 	
 	printf("O quociente �: %d \n", quociente);
 	printf("O resto �: %d \n", resto);
 	
 	system("pause");
 	return (0);
 }
 
