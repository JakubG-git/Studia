#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
/*
char, ASCII
( ) 40, 41
[ ] 91, 93
{ } 123, 125
*/

char *usun_wne(char * tekst){
    char *nawi = tekst;
    while(*nawi != '(' && *nawi != ')' && *nawi != '[' && *nawi != ']' && *nawi != '{' && *nawi != '}' && *nawi != '\0')
        nawi++;
    return nawi;
}


char *nawiasy(char * tekst, char stos){
    char * nawi = tekst;
    char * kopia, *kopia2;
    //pozbywam sie znakow innych niz nawiasy  
    nawi = usun_wne(nawi);
    kopia = nawi;
    while(*nawi){
        if (*nawi == '('){
            kopia2 = nawi;
            if (*(kopia2+1) == '\0')
            {
                return "ba";
            }
            return nawiasy(nawi+1, '(');
        }
        if (*nawi == '['){
            kopia2 = nawi;
            if (*(kopia2+1) == '\0')
            {
                return "bc";
            }
            return nawiasy(nawi+1, '[');
        }
        if (*nawi == '{'){
            kopia2 = nawi;
            if (*(kopia2+1) == '\0')
            {
                return "bd";
            }
            return nawiasy(nawi+1, '{');
        }
        else if ((*nawi == ')' || *nawi == ']' || *nawi == '}')&&(!stos)){
            return "b";
        }
        if(*nawi == ')' && stos == '('){
            return nawiasy(nawi+1, '\0');
        }
        if(*nawi == ']'&& stos == '['){
            return nawiasy(nawi+1, '\0');
        }
        if(*nawi == '}'&& stos == '{'){
            return nawiasy(nawi+1, '\0');
        }
        else
            return "b";
        nawi++;
    }
    return kopia;
}

char *czytaj(void)
{
    char bufor[1000];
    scanf("%s", bufor);
    char *p;
    p = (char*)(malloc((strlen(bufor) + 1)*sizeof(char)));
    if(p == NULL){printf("Brak miejsca"); exit(1);}
    strcpy(p, bufor);
    return p;
}

int main(void){
    char *nawias, *por;
    nawias = czytaj();
    por = usun_wne(nawias);
    nawias = nawiasy(nawias, '\0');
    if(*nawias == 'b'){
        printf("Blendne");
    }
    else
        printf("Poprawne");
}