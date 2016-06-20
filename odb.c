#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>


////FUNKCJE
int spraz(char *a)
    {
    if (((a[0] >= 'a' && a[0] <= 'z') || (a[0] >= 'A' && a[0] <= 'Z'))){return 0;}
    }

int spr19(int dl, char *a)
    {
        int j=0;
        for (j = 0; j < dl; j++)
            {
                if (a[j]<126 || a[j]>32)
                { return 0;}
            }
    }

////FUNKCJE

//STRUCTURA DO OBSŁUGI WIADMOOSCI
struct wiad            //STRUCTURA DO OBSŁUGI WIADMOOSCI
{
	int typ;
	char slowa[20];
};
//STRUCTURA DO OBSŁUGI WIADMOOSCI

int main()
{
//zmiennne
	struct wiad b;         /// zmiennne o strukturze

	int a, rozmiar, d, g;
    //zmiennne

    time_t czas;
    struct tm * data;
    time( & czas );
    data = localtime( & czas );
    mktime( data );
    d=(data->tm_wday);
    g=(data->tm_hour);
    printf("  Dzień: ");
    printf(" %d  ",d);
    printf("  Godzina: ");
    printf(" %d",g);
    printf("\n");
    key_t klucz = 45222;
	a = msgget(klucz, IPC_CREAT | 0660); /// TWORZENIE KOLEJKI KOMUNIKATÓW msgget(klucz, IPC_CREAT | 0660);
    if (a == -1)  ///obsluga bledow
		{
        printf("Blad tworzenia kolejki.\n");
        exit(1);
		}   ///obsluga bledow


if (d == 5)
    {
    if (g < 14)
        {
            printf("Jes normalny dzien, nie weekend\n");
            return 0;
        }

        rozmiar = sizeof (b.slowa);  ///rozmiar tablicy
        a=msgrcv(a, &b, rozmiar, 0,0); /// CZYTANIE SLOWA DO B

		if ( a== -1) ///OBSLUGA BLEDOW
		{
			printf("NIE OTRZYMANO KOMUNIKATU\n");
			return 0;
		}           ///OBSLUGA BLEDOW

		///WARUNEK LICZBOWY
		int dl = strlen(b.slowa);
			if (spr19(dl,b.slowa) ==0)
			{
				msgctl(a, IPC_RMID, NULL);  /// zamkniecie kolejki IPC_RMID Usuwa kolejkę z jądra.
				printf("CIAG SKLADA SIE NIE TYLKO Z ASCI\n");
				return 0;  ///KONCZYMY PRACE PROGRAMU
			}
		///WARUNEK LICZBOWY

		///WARUNEK LITEROWY
		if (spraz(b.slowa)!=0)
		{
			msgctl(a, IPC_RMID, NULL);   /// zamkniecie kolejki IPC_RMID Usuwa kolejkę z jądra.
			printf("CIAG NIE ZACZYNA SIE LITERA\n");
			return 0;  ///KONCZYMY PRACE PROGRAMU
		}
		///WARUNEK LITEROWY

		///OPERACJE NA PLIKACH
		FILE *uchwyt = fopen("klucz.txt", "w");
		fwrite(b.slowa, dl, 1, uchwyt);
		fclose(uchwyt);
		///OPERACJE NA PLIKACH



    }

if (d > 5) /// sprawdzanie DNIA  if (dzien > 5)
	{
		rozmiar = sizeof (b.slowa);  ///rozmiar tablicy
        a=msgrcv(a, &b, rozmiar, 0,0); /// CZYTANIE SLOWA DO B

		if ( a== -1) ///OBSLUGA BLEDOW
		{
			printf("NIE OTRZYMANO KOMUNIKATU\n");
			return 0;
		}           ///OBSLUGA BLEDOW

		///WARUNEK LICZBOWY
		int dl = strlen(b.slowa);
			if (spr19(dl,b.slowa) ==0)
			{
				msgctl(a, IPC_RMID, NULL);  /// zamkniecie kolejki IPC_RMID Usuwa kolejkę z jądra.
				printf("CIAG SKLADA SIE NIE TYLKO Z ASCI\n");
				return 0;  ///KONCZYMY PRACE PROGRAMU
			}
		///WARUNEK LICZBOWY

		///WARUNEK LITEROWY
		if (spraz(b.slowa)!=0)
		{
			msgctl(a, IPC_RMID, NULL);   /// zamkniecie kolejki IPC_RMID Usuwa kolejkę z jądra.
			printf("CIAG NIE ZACZYNA SIE LITERA\n");
			return 0;  ///KONCZYMY PRACE PROGRAMU
		}
		///WARUNEK LITEROWY

		///OPERACJE NA PLIKACH
		FILE *uchwyt = fopen("klucz.txt", "w");
		fwrite(b.slowa, dl, 1, uchwyt);
		fclose(uchwyt);
		///OPERACJE NA PLIKACH
	}
	else { printf("Nie ma weekendu\n"); }
	msgctl(a, IPC_RMID, NULL);   /// zamkniecie kolejki IPC_RMID Usuwa kolejkę z jądra.
	return 0;
}
