#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   //Use appropriate location (Windows, MacOS or Linux)
   //Absolute vs. relative path
   fptr = fopen("C:\\Users\\david\\Desktop\\program.txt","w");
   //fptr = fopen("..\\program.txt","w");
   //fptr = fopen("program.txt","w");

   if(fptr == NULL){
      printf("Error!");
      exit(1);
   }

   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);

   return 0;
}