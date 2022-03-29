#include<stdio.h>
#include<stdbool.h>
void ifTriangle(double a, double b, double c){
    if((a + b > c)&&(a + c > b)&&(c + b > a))
        printf("Bok: %.2f, Bok: %.2f, Bok: %.2f tworza trojkat \n", a, b, c);
}
void czyTrojkaZtab(double *tab, int wymiar){
    int i, j, k;
    for ( i = 0; i < wymiar; i++)
    {
        for (j = i + 1 ; j < wymiar; j++)
        {
            for (  k = j + 1; k < wymiar; k++)
            {
                ifTriangle(tab[i], tab[j], tab[k]);
            }
        }
    }
}




int main(){
    double tab[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(tab) / sizeof(double); 
    czyTrojkaZtab(tab, n);
    return 0;
}