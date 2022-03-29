#include<math.h>
#include<stdio.h>



/* long double powinien wystarczyc */

long double Przykladowa_Funkcja(long double x){
    return 1/((x-0.5)*(x-0.5)+0.01);
}

long double Srodek(long double x, long double y){
    return (x + y) / 2.;
}

unsigned int poziom_rekursji = 16;
 
long double calkuj(long double poczatek_prz, long double koniec_prz, long double srodek_prz,
  long double wart_funkc_poczatek, long double wart_funkc_koniec, long double wart_funkc_srodek,
  long double wart_calki, long double max_dop_bld, int pozostalo_do_max_gl);

int main(void){
    long double poczatek_prz, koniec_prz, srodek_prz, wart_funkc_poczatek,
    wart_funkc_koniec, wart_funkc_srodek,  max_dop_bld, caleczka;
    #pragma region Input
    printf("Podaj poczatek przedzialu calkowania: ");
    scanf("%Lf", &poczatek_prz);
    printf("Podaj koniec przedzialu calkowania: ");
    scanf("%Lf", &koniec_prz);
    printf("Podaj maksymalny dopuszczalny blad: ");
    scanf("%Lf", &max_dop_bld);
    #pragma endregion Input

    srodek_prz = Srodek(poczatek_prz, koniec_prz);

    #pragma region Wart_func
    wart_funkc_poczatek = Przykladowa_Funkcja(poczatek_prz);
    wart_funkc_koniec = Przykladowa_Funkcja(koniec_prz);
    wart_funkc_srodek = Przykladowa_Funkcja(srodek_prz);
    #pragma endregion Wart_func

    #pragma region Wywolanie
    /* (koniec_prz - poczatek_prz) inaczej h  ze wzoru dla poczatkowego przypadku*/
    caleczka = calkuj(poczatek_prz, koniec_prz, srodek_prz,
      wart_funkc_poczatek, wart_funkc_koniec, wart_funkc_srodek,
     (koniec_prz - poczatek_prz) * (wart_funkc_poczatek + 4 * wart_funkc_srodek + wart_funkc_koniec) / 6,
     max_dop_bld, poziom_rekursji);
    printf("Calka wynosi: %.10Lf\n", caleczka);
    #pragma endregion Wywolanie

    return 0;
}

long double calkuj(long double poczatek_prz, long double koniec_prz, long double srodek_prz, long double wart_funkc_poczatek, long double wart_funkc_koniec, long double wart_funkc_srodek, long double wart_calki, long double max_dop_bld, int pozostalo_do_max_gl){

    if(pozostalo_do_max_gl == 0){
        return NAN; /* osiagniento max poziom rekursji */
    }
    #pragma region Deklaracje
    long double srodek_lewej_strony = Srodek(poczatek_prz, srodek_prz),
     srodek_prawej_strony = Srodek(srodek_prz, koniec_prz),
     wart_funkc_srodka_lewej_strony = Przykladowa_Funkcja(srodek_lewej_strony),
     wart_funkc_srodka_prawej_strony = Przykladowa_Funkcja(srodek_prawej_strony),
     wart_calki_lewej_str = (srodek_prz - poczatek_prz) * (wart_funkc_poczatek + 4 * wart_funkc_srodka_lewej_strony + wart_funkc_srodek) / 6, /* S1 ze wzoru*/
     wart_calki_prawej_str = (koniec_prz - srodek_prz) * (wart_funkc_srodek + 4 * wart_funkc_srodka_prawej_strony + wart_funkc_koniec) / 6; /* S2 ze wzoru*/
    long double calkaL, calkaP; /* jesli bedzie potrzeba */
    #pragma endregion Deklaracje

    #pragma region Liczenie
    if(fabsl(wart_calki_lewej_str + wart_calki_prawej_str - wart_calki) <= max_dop_bld){
        printf("Glebokosc: %d, dla przedzialu [%Lf, %Lf]\n", (poziom_rekursji - pozostalo_do_max_gl), poczatek_prz, koniec_prz);
        return (wart_calki_lewej_str + wart_calki_prawej_str);
    }
    calkaL = calkuj(poczatek_prz, srodek_prz, srodek_lewej_strony,  wart_funkc_poczatek, wart_funkc_srodek, wart_funkc_srodka_lewej_strony, wart_calki_lewej_str, max_dop_bld / 2, pozostalo_do_max_gl - 1);
    calkaP = calkuj(srodek_prz, koniec_prz, srodek_prawej_strony,  wart_funkc_srodek, wart_funkc_koniec, wart_funkc_srodka_prawej_strony, wart_calki_prawej_str, max_dop_bld / 2, pozostalo_do_max_gl - 1);
    if(calkaL == NAN)
	    return NAN;
    if(calkaP == NAN)
	    return NAN;
    return (calkaL + calkaP);
    #pragma endregion Liczenie
}