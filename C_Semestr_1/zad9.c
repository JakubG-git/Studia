#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
char **bubble(int n, char **tab){
    int i;
    char *temp;
    do
    {
        for (i = 0; i < n-1; i++){
            if (strcmp(tab[i], tab[i + 1]) > 0){
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
            }
        }
        n-=1;
    } while (n > 1);
    return tab;
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

void func1(){
    int n, najw, i;
    char **tab;
    scanf("%d", &n);
    scanf("%d", &najw);
    tab = (char**)(malloc((n+1)*sizeof(char*)));
    for( i = 0; i < n; i++)
    {
        tab[i] = (char*)(malloc((najw+1)*sizeof(char)));
    }
    for( i = 0; i < n; i++)
    {
        scanf("%s", tab[i]);
    }
    printf("=======\n");
    tab = bubble(n, tab);
    for( i = 0; i < n; i++)
    {
        printf("%s\n", tab[i]);
    }
    free(tab);
}

void func2(){
    int n, i;
    char **tab;
    scanf("%d", &n);
    tab = (char**)(malloc((n+1)*sizeof(char*)));
    for( i = 0; i < n; i++)
    {
        tab[i] = czytaj();
    }
    printf("=======\n");
    tab = bubble(n, tab);
    for( i = 0; i < n; i++)
    {
        printf("%s\n", tab[i]);
    }
    free(tab);
}

int main(){
    func1();
    printf("=======\n");
    func2();
}