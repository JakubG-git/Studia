#include<stdio.h>
int silnia(int n)
{
    if (n == 1  || n == 0)
    {
        return 1;
    } 
    else
    {
        return n * silnia(n-1);
    }
    
}


int main()
{
    printf("%d", silnia(5));
    return 0;
}