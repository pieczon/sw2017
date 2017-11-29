#include <stdio.h>
#include <stdlib.h>

//8.2.5 Napisz funkcję, która dostaje w argumencie ścieżkę dostępu do pliku tekstowego i wypisuje na standardowym wyjściu statystyki występowania w pliku poszczególnych znaków (zakładamy, że znaki są typu char).

void statystyki(char sciezka[])
{
	FILE *fd = fopen(sciezka, "r");
	int znak;
	int tab[256] = {0};
	int ilosc = 0;
	while((znak = fgetc(fd)) != EOF)
	{
		tab[znak] = tab[znak] + 1;
	}
	for(int i=0; i<256; i++)
	{
		if(tab[i] > 0 && i!=10)
		{
			printf("znak %c wystapil %d razy.\n",i,tab[i]);
			if(ilosc < tab[i])
				ilosc = tab[i];
		}
	}
	for(int i=0; i<256; i++)
	{
		if(tab[i] == ilosc)
			printf("Najczesciej występujacy znak to: %c iloscia wystapien: %d\n", i, tab[i]);
    }
    fclose(fd);
}
int main()
{
    statystyki("liczba.c");
}
