#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct  wiad     ///STRUCTURA DO OBSŁUGI WIADMOOSCI
{
int typ;
char slowa[20];
};          ///STRUCTURA DO OBSŁUGI WIADMOOSCI

int main()
{
	int a, rozmiar;
	 ///ZMIENNE ZMIENNE
	struct wiad b;
	 ///TWORZENIE ZMIENNYCH O STUKTURZE



    key_t klucz = 45222;
	a = msgget(klucz, IPC_CREAT | 0660); /// TWORZENIE KOLEJKI KOMUNIKATÓW
	b.typ = 1;   /// PRZYPISYWANIE 1 JESLI DOBRZE STWORZONA

/// OBSUGA UZYTKOWANIKA

	printf("Podaj: ");
	scanf("%s", b.slowa);  ///OBSUGA UZYTKOWANIKA ZAPIS DO

/// OBSUGA UZYTKOWANIKA

	rozmiar = sizeof(b.slowa);  ///ROZMIAR PLIKU DO SIZE

    ///WYSYLANIE

    int blad = (msgsnd(a, &b, rozmiar, 0));  ///wysylanie do kolejki

    ///WYSYLANIE
	if (blad == -1)  /// OBSŁUGA BŁĘDÓW
	{
		printf("BLAD");
		return 0;
	}
	return 0;
}
/// www.linuxpl.org/LPG/node33.html
