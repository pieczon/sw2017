#include <stdio.h>
#include <stdlib.h>

//8.2.6 Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku tekstowego i zwraca jako wartość najczęściej występujący w pliku znak (zakładamy, że znaki są typu char).

void najwystapien(char sciezka[])
{
	FILE *fd = fopen(sciezka, "r");
	int ilosc = 0;
	int znak;
	int tab[256] = {0};
	while((znak = fgetc(fd)) != EOF)
	{
		tab[znak] = tab[znak] + 1;
    }
    fclose(fd);
	for(int i=0; i<256; i++)
	{
		if(tab[i]>0 && i!=10 && i!=32)
		{
			if(ilosc < tab[i])
				ilosc = tab[i];
		}
	}
	for(int i=0; i<256; i++)
	{
		if(tab[i] == ilosc)
			printf("Najczęściej występujacy znak to: -%c- liczba wystąpien: %d\n", i, tab[i]);
    } 
}
int main()
{
    najwystapien("push-to-git.sh");
}
