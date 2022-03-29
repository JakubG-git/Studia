#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

char *zamiana_podstawy(int liczba, int nowa_podstawa){
    int i, j, dlugosc;
    char tab[63];
    char *p;
    for(i = 0;liczba; i++){
        tab[i] = (liczba % nowa_podstawa) + '0';
        liczba /= nowa_podstawa;
    }
    
    dlugosc = i - 1;
    p =  (char*)(malloc((i + 1)*sizeof(char)));
    for ( i = 0, j = dlugosc; i < j; i++, j--)
    {
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
    strcpy(p, tab);
    return p;

}

int main(int argc, char *argv[]){
    char *tab;
    int n;
    if(argc < 3){
        printf("Podaj dwie zmienne: N i p gdzie p nalezy do [1, 10] \n");
        return -1;
    }
    if(argc == 3){
        if(atoi(argv[1]) > 0 && atoi(argv[2]) >= 1 && atoi(argv[2]) <= 10){
           tab = zamiana_podstawy(atoi(argv[1]), atoi(argv[2]));
           n = atoi(tab);
           free(tab);
           return n;
        }
    }

    
}