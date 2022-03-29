#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
char *czytaj(void)
{
    char bufor[1000];
    scanf("%s", bufor);
    int n = strlen(bufor);
    char *p;
    p = (char*)(malloc((n + 1)*sizeof(char)));
    if(p == NULL){printf("Brak miejsca"); exit(1);}
    strcpy(p, bufor);
    return p;
}

int main()
{
    char *p_wiel[5], *p_poj;
    int i;
    for ( i = 0; i < 5; i++){
       p_wiel[i]=czytaj();
    }
    for ( i = 0; i < 5; i++){
       printf("%s \n", p_wiel[i]);
       free(p_wiel[i]);
    }
    return 0;
}