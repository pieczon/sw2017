#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Program ma czytać z pierwszego pliku tylko liczby, a do drugiego wpisuje kwadraty tych liczb

int main()
{
    char znak;
    int kwadrat, cyfra;
    FILE *fr = fopen("plikdoodczytu", "r");
    FILE *fw = fopen("plikdozapisu", "w");
    while(fscanf(fr, "%c", &znak) == 1)
    {
        if(isdigit(znak))
        {
            cyfra = znak - '0';
            kwadrat = pow(cyfra, 2);
            printf("Liczba: %c - do potęgi 2: %d\n", znak, kwadrat);
            

        }
    }
    fclose(fw);
    fclose(fr);
    return 0;
}