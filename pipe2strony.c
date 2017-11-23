#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //biblioteki obsługi pipeline, również write()

int main(int argc, char *argv[])
{

    int fd[2]; //fd[0] - odczyt, fd[1] - zapis;
    int file_descriptor[2];
	int nbytes;
	pid_t childpid; //to jest typ signed int;
	char readbuffer[80];
	char dziecko[] = "Cześć jestem dziecko!\n";
	char rodzic[] = "Cześć jestem rodzic!\n";
	char *p = dziecko;
    pipe(fd); //po wywołaniu funkcji jeśli powodzenie zwraca 0, tablica wypełniana jest 2 nowymi liczbami: deskryptor pliku tylko do odczytu i tylko do zapisu, tworzącymi potok

	if ((childpid = fork()) == -1) //od tego momentu gdy wykona się funkcja fork() mamy już zrobioną kopię procesu, do obsługi komunikacji między procesami mamy utworzony potok pipe()
	{
		perror("Pierwszy potok, nie udało się zrobić fork-a");
		exit(1);
	}
	if (childpid != 0) //proces potomny child ma przekazaną wartość childpid==0, proces rodzica ma childpid!=0 i childpid!=-1
	{
		if (childpid != 0)
		{
			p = rodzic;
		}
		close(fd[0]);
		write(fd[1], p, (strlen(p)+1));
		exit(0);	
	} else //to się wykonuje jednocześnie, proces rodzica i dziecka wykonuje się niezależnie
		{
		close(fd[1]);
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer)); //zwracana przez funkcję write liczba zapisanych bajtów
			if(childpid == 0)
			{
				printf("dziecko ");
			} else
			  {
			  printf("rodzic ");
			  }
		printf("--komunikat: %s", readbuffer);
    	}
    
    pipe(file_descriptor);
		if ((childpid = fork()) == -1) 
		{
            perror("Drugi potok, nie zrobiłem fork-a");
            exit(1);
        }
		if (childpid == 0) 
		{
			if (childpid!=0)
			{
                p = rodzic;
			}
            close(file_descriptor[0]);
            write(file_descriptor[1], p, (strlen(p)+1));
            exit(0);  
		} else 
		  {
		  close(file_descriptor[1]);
		  nbytes = read(file_descriptor[0], readbuffer, sizeof(readbuffer));
			if (childpid == 0)
			{
				printf("dziecko ");
			} else
			  {
				printf("rodzic ");
			  }
          printf("--komunikat: %s", readbuffer);
          }
	return (0);
}
