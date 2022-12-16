 
 #include <stdio.h>
 #include <locale.h>
 
 int main()
 {
 	setlocale(LC_ALL,"");
 	int num;
 	printf("Informe um número: ");
 	scanf ("%d", &num);
 	if (num > 0){
 		printf("O número é positivo. \n");
	 }
	 else
	 {
	 	if (num < 0){
	 		printf("O número é negativo. \n");
		 }
		 else
		 {
		 	printf("É neutro. \n");
		 }
	 }
	 system("pause");
	 return (0);
 }
