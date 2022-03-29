#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

struct Lista_jk {
    int ID;
    char *imie, *nazwisko;
    struct Lista_jk * nastepny;
};

void pisz(struct Lista_jk ** h){
    struct Lista_jk *el = *h;
    while (el){
        printf("[%d, %s %s]\n",el->ID, el->imie, el->nazwisko);
        el = el->nastepny;
    }
}

void dodaj_alf(struct Lista_jk **h, int wartosc, char *imie, char *nazwisko){
   struct Lista_jk *nowy = malloc(sizeof(struct Lista_jk));
    nowy->ID = wartosc;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    if(*h == NULL || strcmp((*h)->nazwisko, nowy->nazwisko) > 0){
        nowy->nastepny = *h;
        *h = nowy;
        return;
    }
    struct Lista_jk *stary = *h;
    while (stary->nastepny != NULL && strcmp(stary->nastepny->nazwisko, nowy->nazwisko) < 0 ) {
        stary = stary->nastepny;
    }
    nowy->nastepny = stary->nastepny;
    stary->nastepny = nowy;
}
void dodaj_po_id(struct Lista_jk **h, int wartosc, char *imie, char *nazwisko){
    struct Lista_jk *nowy = malloc(sizeof(struct Lista_jk));
    nowy->ID = wartosc;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;

    if(*h == NULL || (*h)->ID >= nowy->ID){
        nowy->nastepny = *h;
        *h = nowy;
        return;
    }
    struct Lista_jk *stary = *h;
    while (stary->nastepny != NULL && stary->nastepny->ID < nowy->ID) {
        stary = stary->nastepny;
    }
    nowy->nastepny = stary->nastepny;
    stary->nastepny = nowy;

}

void dodaj_koniec(struct Lista_jk **h, int wartosc, char *imie, char *nazwisko){
    struct Lista_jk *stary = *h, *nowy = malloc(sizeof(struct Lista_jk));
    nowy->ID = wartosc;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->nastepny = NULL;
    if(stary == NULL){
        *h = nowy;
    }
    else{
        while(stary->nastepny != NULL)
            stary = stary->nastepny;
        stary->nastepny = nowy;
    }
}

void dodaj_poczatek(struct Lista_jk **h, int wart, char *imie, char *nazwisko)
{
    struct Lista_jk *nowy = malloc(sizeof(struct Lista_jk));

    nowy->ID = wart;
    nowy->imie = imie;
    nowy->nazwisko = nazwisko;
    nowy->nastepny = *h;
    *h = nowy;
}

void usun(struct Lista_jk **h, int id){
    struct Lista_jk *nowy = *h, *poprzedni = NULL;

    if (nowy != NULL && nowy->ID == id) {
        *h = nowy->nastepny; 
        free(nowy); 
        return;
    }

    while (nowy != NULL && nowy->ID != id) {
        poprzedni = nowy;
        nowy = nowy->nastepny;
    }

    if (nowy == NULL){
        printf("Nie ma takiego id w liscie\n");
        return;
    }
        

    poprzedni->nastepny = nowy->nastepny;

}

char *czytaj(void)
{
    char bufor[1000];
    scanf("%s", bufor);
    char *p;
    p = (char*)(malloc((strlen(bufor) + 1)*sizeof(char)));
    if(p == NULL){printf("Brak miejsca"); exit(1);}
    strcpy(p, bufor);
    return p;
}

void print_Menu(unsigned short type){
    if(type == 1)
        printf("Wybierz opcje\n 'a' dla dodania elementu,\n 'd' dla skasowania elementu wskazanego numerem albumu,\n 'p' dla wyprowadzenia na ekran wszystkich informacji z elementów listy,\n 'x' dla zakończenia programu.\n");
    if (type == 2)
        printf("Wybierz typ wstawienia\n 'f' na początku listy,\n 'e' na końcu listy,\n 'a' zachowując porządek alfabetyczny nazwisk,\n 'n' zachowując uporządkowanie wg numeru ID,\n 'b' wroc do poprzedniego menu.\n");   
}

void bufclean(void){
	char c;
	do{c = getchar();}while (c!='\n');
}