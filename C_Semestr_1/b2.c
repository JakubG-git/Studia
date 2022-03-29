#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int tab_ilosci[RAND_MAX];
int main(){
    long long i;
    long long tmp;
    long long suma =0;
    for ( i = 0; i < (long long)(RAND_MAX) + 1; i++)
    {
        tmp = rand();
        if(tab_ilosci[tmp] >= 1){
            tab_ilosci[tmp] += 1;
        }
        tab_ilosci[tmp] = 1;
    }
    for ( i = 0; i < (long long)(RAND_MAX) + 1; i++){
        printf("Liczba %Ld, wystepuje %d razy\n", i, tab_ilosci[i]);
        suma += tab_ilosci[i];
    }
    printf("Suma krotnosci %Ld\n", suma);
    if(suma == (long long)(RAND_MAX)){
        printf("Suma krotnosci rowna liczbie losowan");
    }
    else
        printf("Nie rowna");
    return 0;
}