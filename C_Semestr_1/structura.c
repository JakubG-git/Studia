#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

enum Marka{
    skoda,
    fiat,
    bwm,
    audi
};

struct Pojazd
{
    int rok;
    float poj;
    enum Marka marka;
    char *nazwisko;
};

char *czytaj(void)
{
    char bufor[1000];
    scanf("%s", bufor);
    int n = strlen(bufor);
    char *p;
    p = (char*)(malloc((n + 1)*sizeof(char)));
    if(p == NULL){printf("Brak miejsca"); exit(1);}
    strcpy(p, bufor);
    return p;
}

void wczytaj(struct Pojazd *samochod){
    scanf("%d", &samochod->rok);
}

void wczytajNazw(struct Pojazd *samochod){
    samochod->nazwisko = czytaj();
}

int main()
{
    struct Pojazd sam1;
    wczytaj(&sam1);
    printf("%d \n", sam1.rok);
    sam1.marka = fiat;
    printf("%d", sam1.marka);
    wczytajNazw(&sam1);
    printf("%s", sam1.nazwisko);
    
}
