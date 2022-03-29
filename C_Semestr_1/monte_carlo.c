#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/*srand(time(0));*/

long double funkcja(long double x){
    return 1/((x-0.5)*(x-0.5)+0.01);
}

long double prostokont(long double a, long double b, long double c, long double d){
    return fabsl((b - a)) * fabsl((d - c));
}

long double losowa_z_przedzialu(long double a, long double b){
    return a + (long double)rand()/(long double)(RAND_MAX) * (b - a);
}

int czyPktFunkcja(long double x, long double y){
    if(y > 0 && y <= funkcja(x)){
        return 1;
    }else if(y < 0 && y >= funkcja(x)){
        return -1;
    }
    return 0;
}

long double calka(long double x1, long double x2, long double y1, long double y2, long int ile_pkt){
    long int i, c = 0; /* ze wzoru ilosc, pkt trafionych */
    for(i = 0; i <= ile_pkt; i++){
        c += czyPktFunkcja(losowa_z_przedzialu(x1, x2), losowa_z_przedzialu(y1, y2));
    }
    
    return (prostokont(x1, x2, y1, y2) * (c / (long double)ile_pkt));
}

int main(void){
    #pragma region Input_Dekralacja
    long double poczatek_prz, koniec_prz, ogra_gora, ogra_dol, caleczka;
    long int licz_pkt;
    printf("Podaj poczatek przedzialu calkowania: ");
    scanf("%Lf", &poczatek_prz);
    printf("Podaj koniec przedzialu calkowania: ");
    scanf("%Lf", &koniec_prz);
    printf("Podaj wartosc ograniczajaca od gory: ");
    scanf("%Lf", &ogra_gora);
    printf("Podaj wartosc ograniczajaca od dolu: ");
    scanf("%Lf", &ogra_dol);
    if(ogra_gora < ogra_dol){
        long double tmp = ogra_gora;
        ogra_gora = ogra_dol;
        ogra_dol = tmp;
    }
    printf("Podaj liczbe pkt: ");
    scanf("%ld", &licz_pkt);
    #pragma endregion Input_Dekralacja

    caleczka = calka(poczatek_prz, koniec_prz, ogra_gora, ogra_dol, licz_pkt);
    printf("Calka wynosi: %.16Lf\n", caleczka);
}