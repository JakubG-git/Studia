#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int i;
    int suma = 0;
    if(argc < 3){
        printf("Podaj dwie zmienne: odjemna i odjemnik \n");
        return -1;
    }
    if (argc == 3)
    {
        return (atoi(argv[1]) - atoi(argv[2]));
    }
    if(argc > 3){
        for ( i = 1; i < argc; i++)
        {
            suma += atoi(argv[i]);
        }
        printf("%d", suma);
        return suma;
        
    }
}