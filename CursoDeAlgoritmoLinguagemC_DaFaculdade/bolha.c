#include<stdio.h>
int main(){
   int count, temp, i, j, num[30];
   printf("Quantos numeros deseja informar?: ");
   scanf("%d",&count);
   printf("Digite os numeros: ",count);
     for(i=0;i<count;i++)
   scanf("%d",&num[i]);
   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(num[j]>num[j+1]){
           temp=num[j];
           num[j]=num[j+1];
           num[j+1]=temp;
        }
      }
   }

   printf("Elementos ordenados: ");
   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}
