#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>

unsigned int pozycja_pierwszej_litery[33]; 


void pierwsze_litery(FILE *PLIK){
    /* znajduje pozycje pierwszej litery np 100 1000 itp*/   
    char litera_przed = 97, slowa[256]; /* najdluzszy wyraz polski ma 32 + 1 dla '\0' */
    pozycja_pierwszej_litery[0] = 0;
    fseek(PLIK, 0, SEEK_SET);
    while(!feof(PLIK)){
        fscanf(PLIK, "%255s", slowa);
        if(*slowa){
            if(*slowa != litera_przed){
                pozycja_pierwszej_litery[*slowa - 97] = ftell(PLIK) - strlen(slowa);
                litera_przed = *slowa;
            }
            else if(*slowa == 122){
                pozycja_pierwszej_litery[*slowa - 97] = ftell(PLIK) - strlen(slowa);
                 /*koniec znaleziono litere 'z'  koniec alfabetu */
                break;
            }
        }
    }
}


void wroc_na_poczatek_slowa(FILE *PLIK){
    /* przez losowe losowanie zdaza sie ze wskaznik pliku laduje w srodku slowa ta funkcja wraca na poczatek (pierwsza litere) */
    while(ftell(PLIK) != 0 && fgetc(PLIK) != '\n')
        fseek(PLIK, -2, SEEK_CUR);
}

int ile_slow_na_dana_litere(int dlugosc_pliku, char litera){
    /* funkcja zwraca ilosc slow na dana litere */
    if (litera == 'z') return dlugosc_pliku - pozycja_pierwszej_litery[litera - 97];  /*z jako ostatnia litera */
    else{
        return (pozycja_pierwszej_litery[litera - 97 + 1] - pozycja_pierwszej_litery[litera - 97]); /* pozycja danej litery */
    }
        
}

void wypisz(char wylosowane[4][256]){
    /* wypisuje slowa w kolejnosci gora lewo prawo dol */
    printf("%s\n", wylosowane[0]); /* gora */
    for(size_t i = 1;wylosowane[1][i + 1] != '\0'; i++){
        printf("%c", wylosowane[1][i]); /* lewo */
        for (size_t j = 0;wylosowane[0][j + 2] != '\0'; j++){
            printf("%s", " "); /* wypelnienie (srodek) */
        }
        printf("%c\n",wylosowane[2][i]); /* prawo */
    }
    printf("%s\n", wylosowane[3]); /* dol */
}

void krzyzowka(FILE *PLIK, int dlugosc, char wylosowane[4][256]){
    int dlugosc_slowa[4];
    int ile_slow;
    char litera, litera_2;
    for ( size_t i = 0; i < 16; i++)
    {
        fseek(PLIK, rand() % dlugosc, SEEK_SET);
        wroc_na_poczatek_slowa(PLIK);
        fscanf(PLIK, "%255s", wylosowane[0]); /* pierwsze wylosowane slowo GORA*/
        dlugosc_slowa[0] = strlen(wylosowane[0]);
        if (dlugosc_slowa[0] <= 2) continue; /* losujemy nastepny raz  wylosowane za krotkie*/
        for ( size_t j = 0; j < 16; j++)
        {
            litera = wylosowane[0][0];
            ile_slow = ile_slow_na_dana_litere(dlugosc, litera);
            fseek(PLIK, (int)rand() % ile_slow + pozycja_pierwszej_litery[litera - 97], SEEK_SET); /*!!*/
            wroc_na_poczatek_slowa(PLIK);
            fscanf(PLIK, "%255s", wylosowane[1]); /* drugie wylosowane slowo  LEWO*/
            dlugosc_slowa[1] = strlen(wylosowane[1]);
            if (dlugosc_slowa[1] <= 2) continue; /* losujemy nastepny raz  wylosowane za krotkie*/

            for (size_t k = 0; k < 16; k++)
            {
                litera = wylosowane[0][dlugosc_slowa[0] - 1]; /* ze wzg ze losujemy prawa czesc krzyzowki potrzebujemy litere na koncu(z gornego slowa) */
                ile_slow = ile_slow_na_dana_litere(dlugosc, litera);
                fseek(PLIK, (rand() % ile_slow) + pozycja_pierwszej_litery[litera - 97], SEEK_SET);
                wroc_na_poczatek_slowa(PLIK);
                fscanf(PLIK, "%255s", wylosowane[2]); /* trzecie wylosowane slowo PRAWO */
                dlugosc_slowa[2] = strlen(wylosowane[2]);
                if (dlugosc_slowa[1] <= 2) continue; /* losujemy nastepny raz  wylosowane za krotkie*/
                for (size_t n = 0; n < 16; n++)
                {
                    litera = wylosowane[1][dlugosc_slowa[1] - 1]; /* ze wzg ze losujemy dolna czesc krzyzowki potrzebujemy litere na koncu(z lewego slowa) */
                    litera_2 = wylosowane[2][dlugosc_slowa[2] - 1]; /* ze wzg ze losujemy dolna czesc krzyzowki potrzebujemy litere na koncu(z prawego slowa) */
                    ile_slow = ile_slow_na_dana_litere(dlugosc, litera);
                    fseek(PLIK, (rand() % ile_slow) + pozycja_pierwszej_litery[litera - 97], SEEK_SET);
                    wroc_na_poczatek_slowa(PLIK);
                    fscanf(PLIK, "%255s", wylosowane[3]); /* trzecie wylosowane slowo PRAWO */
                    dlugosc_slowa[3] = strlen(wylosowane[3]);
                    if(dlugosc_slowa[3] != dlugosc_slowa[0] || dlugosc_slowa[1] != dlugosc_slowa[2] || wylosowane[3][dlugosc_slowa[3] - 1] != litera_2)
                        continue; /* losujemy nastepny raz poniewaz dlogosc slow sie niezgadzaja lub koniec[litera] slowa dolnego sie nie zgdza */
                    return;
                }
                
            }
            
        }
        

    }
    
}



int main(){
    srand(time(NULL));
    FILE *PLIK;
    int dlugosc;
    char wylosowane[4][256];
    PLIK = fopen("slowa", "r");if(PLIK == NULL) return 0; /* wczytanie pliku */
    fseek(PLIK, 0, SEEK_END);
    dlugosc = ftell(PLIK);
    pierwsze_litery(PLIK);

    krzyzowka(PLIK, dlugosc, wylosowane);

    wypisz(wylosowane);

    fclose(PLIK);

}