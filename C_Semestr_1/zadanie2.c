#include<stdio.h>
#include<limits.h>
void Min_Max(int *tab, int n, int *min, int *max);

int main()
{
    int tab[] = {1,3,6,2,-1,20,0,-20,12,34,7,9};
    int n = sizeof(tab) /sizeof(tab[0]);
    int min,max;
    Min_Max(tab, n, &min, &max);
    printf("Min: %d, Max: %d", min, max);
    return 0;
}

void Min_Max(int *tab, int n, int *min, int *max)
{
    int i;
    *min = INT_MAX;
    *max = INT_MIN;
    for(i = 0; i < n; i++)
    {
        if(*min > tab[i])
        {
           *min = tab[i];
        }
    }
    for(i = 0; i < n; i++)
    {
        if(*max < tab[i])
        {
            *max = tab[i];
        }
    }
}