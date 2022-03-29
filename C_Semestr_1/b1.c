#include<math.h>
#include<stdio.h>
#include<stdlib.h>
 int tab[(long long)(RAND_MAX)+1];

int szukaj(int x){
    long long i;
    for (i = 0; i < (long long )(RAND_MAX)+1; i++)
        if (tab[i] == x)
            return 1;
    return 0;
}

int main(){
    long long i;
    int counter = 0;

    for ( i = 0; i < ((long long)(RAND_MAX)+1); i++)
    {
        tab[i] = rand();
    }
    for ( i = 0; i < ((long long)(RAND_MAX)+1); i++)
    {
        if(szukaj(i)){
            counter++;
        }else{
            return 0;
        }
    }
    
    return 0;
    
}