#include<stdlib.h>
#include<stdio.h>
#include<strings.h>
//fseek
//ftell
int main()
{
    FILE *plik = fopen("slowa", "r");
    char bufor[10000];int i;
    if(plik == NULL)
    {
        return -1;
    }
    for (i = 0; i < 10; i++)
    {
        fgets(bufor, 10000, plik);
        printf("%s", bufor);
    }
    fclose(plik);

}