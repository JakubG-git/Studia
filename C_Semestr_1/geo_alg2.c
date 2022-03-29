#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

double iloczynSkalarny(double *wektorA, double *wektorB, int wymiar){
    double suma = 0;
    int i;
    for ( i = 0; i < wymiar; i++)
    {
        suma += (wektorA[i]*wektorB[i]);
    }
    return suma;
}

bool prostopadloscWektorow(double *wektorA, double *wektorB){
    if(iloczynSkalarny(wektorA, wektorB, 5) == 0)
        return true;
    return false;
}

bool rownolegloscWektorow(double *wektorA, double *wektorB, int wymiar){
    
    
}


int main(){
    double wektorA[5] = {0, 1, 2, 3, 0};
    double wektorB[5] = {0, 2, 4, 6, 0};
    int i;
    for ( i = 0; i < 5; i++)
    {
        scanf("%lf", &wektorA[i]);
    }
    printf("wektor2: \n");
    for ( i = 0; i < 5; i++)
    {
        scanf("%lf", &wektorB[i]);
    }
    

    if (prostopadloscWektorow(wektorA, wektorB))
    {
        printf("Sa prostopadle \n");
    }
    if (rownolegloscWektorow(wektorA, wektorB, 5))
    {
        printf("Sa rownolegle");
    }
    
    
    return 0;
}
