#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
/* Jakub Głowacki Program niepoprawnie zlicza unikalne slowa i nie wiem dlaczego  A0, P1, Z1*/
/* Planuje poprawe programu */

struct Lista_jk {
    int krotnosc;
    char *wyraz;
    struct Lista_jk * nastepny;
};

void pisz(struct Lista_jk **h){
    struct Lista_jk *el = *h;
    while (el){
        printf("[%d, %s]\n",el->krotnosc, el->wyraz);
        el = el->nastepny;
    }
}

void *usun_smieci(char * tekst){
    char *wsk = tekst;
    
    while(*tekst)
    {
	if(*tekst == '(' || *tekst == ')' || *tekst == '.' || *tekst == ',' || *tekst == ':' || *tekst == '\'' || *tekst == '\"' || *tekst == '?')
	    tekst++;
	else
	    *wsk++ = *tekst++;
    }

    *wsk = *tekst;
}

void usun_duplikat_i_zwieksz_krotnosc(struct Lista_jk *glowa){
    struct Lista_jk *ten = glowa;if(ten == NULL){return;}

    struct Lista_jk *nowy;


    while (ten != NULL && ten->nastepny != NULL){
        nowy = ten;
        while (nowy->nastepny != NULL){
            if (strcmp(ten->wyraz, nowy->nastepny->wyraz) == 0){
                ten->krotnosc += 1;
                nowy->nastepny = nowy->nastepny->nastepny;
            }
            else
            {
                nowy = nowy->nastepny;
            }
        }
        ten = ten->nastepny;
    }

}

void dodaj(struct Lista_jk **h, char *bufor)
{
    /*char *p = (char*)(malloc(strlen(bufor + 1) * sizeof(char)));
    strcpy(p, bufor);*/
    struct Lista_jk *nowy = malloc(sizeof(struct Lista_jk));
    nowy->krotnosc = 1;
    nowy->wyraz = bufor;
    nowy->nastepny = (*h);
    (*h) = nowy;
}

void zapisz_do_pliku(struct Lista_jk **glowa, FILE *plik_wyjscie){
    struct Lista_jk *nowy = *glowa;
    while (nowy)
    {
       fprintf(plik_wyjscie, "[Krotnosc: %d, %s]\n", nowy->krotnosc, nowy->wyraz);
       nowy = nowy->nastepny;
    }
    
}

void zliczanie(struct Lista_jk **glowa, int *wszystkie, int *unikalne){
    struct Lista_jk *ten = *glowa;if(ten == NULL){return;}

    while (ten){
        if(ten->krotnosc == 1){
            (*unikalne)++;
        }
            (*wszystkie) += ten->krotnosc;
            ten = ten->nastepny;
    }
    
}

int main(){
    struct Lista_jk *glowa = NULL;
    char slowo[350];
    int wszystkie = 0, unikalne = 0;
    FILE *plik, *plik_wyjscie;
    plik = fopen("tekst_windows.txt", "r");if(plik == NULL) return 0;
    plik_wyjscie = fopen("tekst_wyjscie.txt", "w");
    /* A-Zz-a 0-9 ' / () . , :  " ? */
    while(fscanf(plik, "%s", slowo) == 1){
        char *p = (char*)(malloc((strlen(slowo) + 1) * sizeof(char)));
        strcpy(p, slowo);
        usun_smieci(p);
        dodaj(&glowa, p);
    } 
    
    fclose(plik);
    usun_duplikat_i_zwieksz_krotnosc(glowa);
    pisz(&glowa);
    zliczanie(&glowa, &wszystkie, &unikalne);
    printf("%d %d", wszystkie, unikalne);
    zapisz_do_pliku(&glowa, plik_wyjscie);
    fclose(plik_wyjscie);

    return 0;
}