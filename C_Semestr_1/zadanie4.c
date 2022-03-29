#include<stdio.h>

bombel_alfa(char tab[][12]){
    int i;
    int n = 12;
    char *tmp;
    while(n){
        for (i = 0; i < n - 1; i++){
            if (tab[i] > tab[i + 1]){   
                tmp = tab[i + 1];
                tab[i + 1] = tab[i];
                tab[i] = tmp;
            }
        }
        n -= 1;    
    }

    
}

int main(){
    int tab[2]; /*tablica 2 elementow typu int */
    int *tab2[2]; /*tablica wskaznikow */
    int *wsk = tab;
    char *miesc[12] = {
        "styczen", "luty", "marzec", "kwiecien",
        "maj", "czerwiec", "lipiec", "sierpien",
        "wrzesien", "pazdziernik", "listopad", "grudzien"};
    char msc[12][12] = {
        "styczen", "luty", "marzec", "kwiecien",
        "maj", "czerwiec", "lipiec", "sierpien",
        "wrzesien", "pazdziernik", "listopad", "grudzien"};
    return 0;
}