#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Program ma czytać z pierwszego pliku tylko liczby, a do drugiego wpisuje kwadraty tych liczb

int main()
{
   char c;
   int kwadrat, liczba;
   FILE *fr = fopen("plikdoodczytu", "r");
   FILE *fw = fopen("plikdozapisu", "w");

   while(fscanf(fr, "%d", &liczba) != fgetc(fr))
   {
        fscanf(fr, "%d", &liczba);
        kwadrat = liczba * liczba;
        printf("%d do potęgi 2: %d\n", liczba, kwadrat);
        fprintf(fw, "%d do potęgi 2: %d\n", liczba, kwadrat);
   }
   fclose(fw);
   fclose(fr);
   return 0;
}