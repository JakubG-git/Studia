#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void zamiana_plus(char *wyraz){
    
    int i;
    for (i = 0; (i < 1000) && *(wyraz + i) != '\0'; i++)
    {
        if(*(wyraz + i) == '-'){
            *(wyraz + i) = '+';
        }
    }
}

void zamiana_tab(char *wyraz){
    int i;
    for (i = 0; (i < 1000) && *(wyraz + i) != '\0'; i++)
    {
        if(*(wyraz + i) == '\''){
            *(wyraz + i) = '\t';
        }
    }
    
}

void usun_cyfr(char *wyraz){
    int i, j;
    int n = strlen(wyraz);
    for ( i = j = 0; (i < n) ; i++)
    {
        if (!((int)(*(wyraz + i)) >= 48 && (int)(*(wyraz + i)) <= 57))
        {
            *(wyraz + j++) = *(wyraz + i);
        }
    }
    wyraz[j] = '\0';
    
}

void usun_cyfry(char *lanc, char l)
{
    char *wsk = lanc;
    
    while(*lanc)
    {
	if(*lanc == l)
	    lanc++;
	else
	    *wsk++ = *lanc++;
    }

    *wsk = *lanc;
}

void zamien_AGH(char *lanc)
{
    char *wsk, *pocz = lanc;
    static char *AGH = "AGH";
    
    while(*lanc)
    {
	    wsk = lanc;
	    while(wsk - lanc < 3 && *wsk)
	    {
	        if(AGH[wsk - lanc] == *wsk)
	        {
		        if(wsk - lanc == 2)
		        {
		            /* znaleziono */
		            *lanc = '*';
		            *(lanc + 1) = *(lanc + 2) = 1;
		            lanc += 2;
		            break;
		        }
		        wsk++;
	        }
	        else
		        break;
	    }

	    lanc++;
    }

    wsk = lanc = pocz;

    while(*lanc)
    {
	    if(*lanc != 1)
	        *wsk++ = *lanc++;
	    else
	        lanc++;
    }

    *wsk = *lanc;
}

void zamien_AGH2(char **lancuch)
{
    char *wsk, *drugi, *lanc = *lancuch;
    int ile = 0;
    
    while(*lanc)
    {
	    if(*lanc++ == 'A')
	        ile += 3;
	    else
	        ile++;
    }

    lanc = *lancuch;

    wsk = drugi = malloc(sizeof(char) * (ile + 1));

    while(*lanc)
    {
	    if(*lanc != 'A')
	        *wsk++ = *lanc++;
	    else
	    {
	        *wsk++ = *lanc++;
	        *wsk++ = 'G';
	        *wsk++ = 'H';
	    }
    }

    free(*lancuch);

    *lancuch = drugi;
}

int main()
{
    char *wyraz;
    wyraz = (char*)(malloc(1000*sizeof(char)));
    scanf("%s", wyraz);
    usun_cyfry(wyraz, 'c');
    printf("%s", wyraz);
    free(wyraz);
}

    //check_AGH(wyraz);
    //zamien_AGH(wyraz);
    //zamien_AGH2(&wyraz);