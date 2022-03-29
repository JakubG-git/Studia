#include<stdbool.h>
#include<stdio.h>

/* Jakub Glowacki grupa 1b Czwaterk */

double iloczynSkalarny(double *wek, double *wek2){
    return (wek[0] * wek2[0]) + (wek[1] * wek2[1]);
}
void createVector(double *a, double *b, double *wektor){
    wektor[0] = b[0] - a[0];
    wektor[1] = b[1] - a[1];
}
bool checkIfNonZeroVector(double *wektor){
    if(wektor[0] == 0 && wektor[1] == 0){
        return false;
    }
    return true;
}

bool ifTriangeRectangular2(double *a, double *b, double *c){
    double wektorAB[2];
    double wektorAC[2];
    double wektorBC[2];
    createVector(a, b, wektorAB);
    createVector(a, c, wektorAC);
    createVector(b, c, wektorBC);
    if(
        !(checkIfNonZeroVector(wektorAB) 
        && checkIfNonZeroVector(wektorAC) 
        && checkIfNonZeroVector(wektorBC))){
            return false;
            /* jesli wektror zerowy to nie ma trojkta*/
    }
    double iloczynSkalarny1 = iloczynSkalarny(wektorAB, wektorBC);
    double iloczynSkalarny2 = iloczynSkalarny(wektorAB, wektorAC);
    double iloczynSkalarny3 = iloczynSkalarny(wektorAC, wektorBC);
    /* jesli nawet jeden z iloczynow skalarnych jest rowny zero to trojkat jest prostokatny */
    if(iloczynSkalarny1  == 0|| iloczynSkalarny2  == 0|| iloczynSkalarny3 == 0){
        return true;
    }
    return false;
}
void czyTrojkaZtab(double tab[][2], int wymiar){
    int i, j, k;
    double tab2[2];
    double tab3[2];
    double tab4[2];
    for ( i = 0; i < wymiar; i++)
    {
        for (j = i + 1 ; j < wymiar; j++)
        {
            for ( k = j + 1; k < wymiar; k++)
            {
                tab2[0] = tab[i][0];
                tab2[1] = tab[i][1];
                tab3[0] = tab[j][0];
                tab3[1] = tab[j][1];
                tab4[0] = tab[k][0];
                tab4[1] = tab[k][1];
                if(ifTriangeRectangular2(tab2, tab3, tab4)){
                    printf("{%f, %f}, {%f, %f}, {%f, %f} \n" ,tab2[0], tab2[1], tab3[0], tab3[1], tab4[0], tab4[1]);
                }
            }
        }
    }
}

int main(){
    double tab[10][2] = {{1, 0}, {0, 1}, {0, 0}, {-1, 2}, {1.5, 5}, {9, 10}, {-2, 5}, {12, 2}, {20, 10}, {25.1, 12}};
    czyTrojkaZtab(tab, 10);
    /* kombinacja 3 z 10 */
}