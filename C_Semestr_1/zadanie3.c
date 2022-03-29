#include<stdio.h>
#include<limits.h>

void matrix_sum(int a[][2], int b[][2], int sum[][2]);

void wypisz(int a[][2], int b[][2], int sum[][2]);

int main()
{
    int tab[2][2] = {{1,2},{2,1}};
    int tab2[2][2] = {{3,4},{3,1}};
    int sum[2][2];
    int rows = 2, columns = 2;
    matrix_sum(tab, tab2, sum);
    wypisz( tab, tab2, sum);
    return 0;
}

void matrix_sum(int a[][2], int b[][2], int sum[][2]){
    int i,j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
        
    }
}

void wypisz(int a[][2], int b[][2], int sum[][2])
{
    int i,j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d + %d = %d", a[j][i], b[i][j], sum[i][j]);
            printf("\n");
        }
        
    }
    

}