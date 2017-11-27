#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Program ma zapisać do drugiego pliku, te linijki z otwartego pliku, zawierające cyfry

#define N 200
char buff[200] = {0};

int liniazawieracyfre(char *l)
{
    int znaleziono = 0;
    while(0!=*l) //sprawdzamy czy wsk nie wskazuje na zero, po lewej stronie wartość nieprzepisywalna, bo pod nia nie mozna nic przypisac, zapis rownowazny (*l!=0)
    {
        if(isdigit(*l))
        {
            znaleziono++; //sprawdzamy tylko czy mamy cyfre w linijce
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
        }
    }
    fclose(fw);
    fclose(fr);
    return 0;
}
