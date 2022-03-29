#include<stdio.h>

void vector_sum(int *a, int *b, int *sum, int n);

void wypis(int *a, int *b, int *sum, int n);

int main()
{
    int a1[5] = {1,2,3,4,5};
    int b1[5] = {2,3,4,5,6};
    int a2[8] = {0,1,2,3,4,5,6,7};
    int b2[8] = {1,2,3,4,5,6,7,8};
    int sum[8];
    int n = sizeof(a1) / sizeof(int);
    int n2 = sizeof(a2) / sizeof(int);
    vector_sum(a1, b1, sum, n);
    wypis(a1, b1, sum, n);
    vector_sum(a2, b2, sum, n2);
    wypis(a2, b2, sum, n2);
    return 0;
}
void vector_sum(int *a, int *b, int *sum, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        sum[i] = a[i] + b[i];
    }
}


void wypis(int *a, int *b, int *sum, int n)
{
    int i;
    for(i = 0;i < n; i++)
    {
        printf("%d + %d = %d \n", a[i], b[i], sum[i]);
    }
    printf("\n");
}