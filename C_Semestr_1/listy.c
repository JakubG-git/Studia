#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include"lista.h"

int main(){
    struct Lista_jk *head = NULL;
    int i = 1, j = 0;
    unsigned short id;
    char one, two;
    char *imie, *nazwisko;
    while(i){
        print_Menu(1);
        scanf("%c", &one);
        bufclean();
        if(one == 'a'){
            j = 1;
            while(j){
                print_Menu(2);
                scanf("%c", &two);
                bufclean();
                if (two == 'f')
                {
                    imie = czytaj();
                    nazwisko = czytaj();
                    id = atoi(czytaj());
                    dodaj_poczatek(&head, id, imie, nazwisko);
                }
                if (two == 'e')
                {
                    imie = czytaj();
                    nazwisko = czytaj();
                    id = atoi(czytaj());
                    dodaj_koniec(&head, id, imie, nazwisko);
                }
                if (two == 'a')
                {
                    imie = czytaj();
                    nazwisko = czytaj();
                    id = atoi(czytaj());
                    dodaj_alf(&head, id, imie, nazwisko);
                }
                if (two == 'n')
                {
                    imie = czytaj();
                    nazwisko = czytaj();
                    id = atoi(czytaj());
                    dodaj_po_id(&head, id, imie, nazwisko);
                }
                if (two == 'b')
                {
                    j = 0;
                }
            }
        }
        if (one =='d')
        {
            printf("Podaj ID\n");
            usun(&head, atoi(czytaj()));

        }
        if (one == 'p')
        {
            pisz(&head);
        }
        if (one == 'x')
        {
            free(head);
            free(imie);
            free(nazwisko);
            i = 0;
        }
        
    }
    return 0;
}