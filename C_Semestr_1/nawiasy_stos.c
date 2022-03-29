#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"stack.h"

/*
char, ASCII
( ) 40, 41
[ ] 91, 93
{ } 123, 125
*/
int nawiasy(char * tekst){
    struct Stack* stos = createStack(300);
    while(*tekst){
        if(*tekst == '(' || *tekst == '[' || *tekst == '{'){
            push(stos, *tekst);
        }else if(*tekst == ')'){
            if(peek(stos) == '(')
                pop(stos);
            else
                return 0;
        }else if( *tekst == ']'){
            if(peek(stos) == '[')
                pop(stos);
            else
                return 0;
        }else if( *tekst == '}'){
            if(peek(stos) == '{')
                pop(stos);
            else
                return 0;
        }
        tekst++;
    }
    if(isEmpty(stos))
        return 1;
    else
        return 0;
    
}

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

int main(){
    char *nawias;
    nawias = czytaj();
    if(nawiasy(nawias))
        printf("Poprawna\n");
    else
    printf("Nie poprawna");
    free(nawias);
    return 0;
}