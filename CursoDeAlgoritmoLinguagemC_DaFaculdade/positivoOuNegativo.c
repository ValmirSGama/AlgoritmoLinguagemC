 
 #include <stdio.h>
 #include <locale.h>
 
 int main()
 {
 	setlocale(LC_ALL,"");
 	int num;
 	printf("Informe um n�mero: ");
 	scanf ("%d", &num);
 	if (num > 0){
 		printf("O n�mero � positivo. \n");
	 }
	 else
	 {
	 	if (num < 0){
	 		printf("O n�mero � negativo. \n");
		 }
		 else
		 {
		 	printf("� neutro. \n");
		 }
	 }
	 system("pause");
	 return (0);
 }
