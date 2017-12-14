#include <stdio.h>
#include <stdlib.h>

//sortowanie przez scalanie

int main()
{
	int tab[8] = {6,5,3,1,8,7,2,4};
	int temp = 0;
	int n = sizeof(tab) / sizeof(int);

	for (int i=0;i<n;i++) //wypisanie el. tablicy wejściowej
	{
		printf("El. nieposortowany: %d\n", tab[i]);
	}
	
	printf("Połowa zbioru: %d", n);

	while(n>1)
	{
		for(int i=0;i<n-1;i++)
		{
			if (tab[i] > tab[i+1])
			{
				temp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = temp;
			}
		}
		n = n-1;
	}
	printf("\n");
	n = sizeof(tab) / sizeof(int);

	for (int i=0;i<n;i++)
        {
                printf("El. posortowany: %d\n", tab[i]);
        }

}