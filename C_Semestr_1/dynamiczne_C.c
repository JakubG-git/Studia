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
    char **p_wiel, *p_poj;
    
    p_wiel = malloc(sizeof(char*));
    int i = 0, n;
    do{
        p_wiel = realloc(p_wiel,  sizeof(char*) * i+2);
        p_wiel[i]=czytaj();
        i++;
    }while(strcmp(p_wiel[i-1], "q"));
    for ( n = 0; n < i - 1; n++){
       printf("%s \n", p_wiel[i]);
       free(p_wiel[i]);
    }
    return 0;
}