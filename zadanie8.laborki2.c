#include <stdio.h>
#include <stdlib.h>

#define N 99
//Program ma zapisać do drugiego pliku linijki otwartego pliku zawierające cyfry
char buff[100] = {0};



// void zcyframi(char *sciezka, char *zapis)
// {
//     char c;
//     printf("Deskryptor: %p\nPlik odczytu: %s\n", fr, sciezka);
//     printf("Plik zapisu: %s\n", zapis);
//     int znak;
// 	int tab[256] = {0};
// 	while((znak = fgetc(fr)) != EOF)
// 	{
// 		tab[znak] = tab[znak] + 1;
//     }
//     while(fscanf(fr,"%c", &c) == 1)
//     {
//         for(int i=0; i<256; i++)
//         {
//             if(tab[i]>0 && (i>=48 && i<=57))
//             {
//                 fprintf(fw, "%c", c);
//             }
//         }
//     }
//     printf("\n");
//     fclose(fw);
//     fclose(fr);
// }
int liniazawieracyfre(char *l)
{
    int znaleziono = 0;
    while(0!=*l) //sprawdzamy czy wsk nie wskazuje na zero, po lewej stronie wartość nieprzepisywalna, bo pod nia nie mozna nic wpisac, wiec warunek bedzie dobrze zapisany, zapis rownowazny (*l==0)
    {
        if(isdigit(l))
        {
            znaleziono++; //sprawdzamy tylko czy mamy cyfre w linijsce
        }
        l++; //przesuwamy sie wskaznikiem, niezaleznie od znalezienia
    }
    return znaleziono;
}
int main()
{
    FILE *fr = fopen("plikdoodczytu", "r");
    FILE *fw = fopen("plikdozapisu", "w");
    while(!feof(fr))
    {
        fgets(buff, N, fr);
        if(liniazawieracyfre(buff))
        {
        fputs(buff, fw);
        fclose(fw);
        fclose(fr);
        }
    }
    return 0;
}
