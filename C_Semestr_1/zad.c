#include<stdlib.h>
#include<stdio.h>
#include<strings.h>

int main(void){
    FILE *plik;
    FILE *plik2;
    char *content;
    unsigned short size_f;
    plik = fopen("input.txt", "rb");if(plik == NULL) return 0;
    plik2 = fopen("output.txt", "wb");if(plik2 == NULL) return 0;
    fseek(plik, 0, SEEK_END);
    size_f = ftell(plik);
    rewind(plik);
    content = malloc(size_f);if(content == NULL) return 0;
    fread(content,size_f,1,plik);
    printf("%s", content);
    for (size_t i = 0; i < 3; i++)
    {
        fwrite(content, size_f,1, plik2);
        fputc('\n', plik2);
    }
    fseek(plik2, size_f+1, SEEK_SET);
    memset(content, 'A', size_f);if(content == NULL) return 0;
    fwrite(content, size_f, 1, plik2);

    
    fclose(plik);
    fclose(plik2);
    free(content);
}